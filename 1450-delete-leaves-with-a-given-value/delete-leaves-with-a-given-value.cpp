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
    TreeNode* helper(TreeNode* root,int target){
        if(root==NULL){
            return NULL;
        }

        root->left = helper(root->left,target);
        root->right = helper(root->right,target);

        if(root->left==NULL && root->right==NULL && root->val==target){
            return NULL;
        }

        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return helper(root,target);
    }
};