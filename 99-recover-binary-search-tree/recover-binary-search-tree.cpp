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
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }

        inOrder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first = prev;
                second = root;
            }
            else{
                second = root;
            }
        }
        prev = root;
        inOrder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = second = NULL;
        prev = new TreeNode(INT_MIN);
        inOrder(root);

        swap(first->val,second->val);
    }
};