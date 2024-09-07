/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool dfs(TreeNode* node, ListNode* head){
        if(head==NULL){
            return true;
        }
        if(node==NULL){
            return false;
        }

        bool ans = false;

        if(node->val==head->val){
            ans |= dfs(node->left,head->next);
            ans |= dfs(node->right,head->next);
        }

        return ans;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL){
            return false;
        }

        bool res = dfs(root,head);

        res |= isSubPath(head, root->left);
        res |= isSubPath(head, root->right);

        return res;
    }
};