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
    bool helper(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }

        bool evaluateLeft = helper(root->left);
        bool evaluateRight = helper(root->right);

        bool res;

        if(root->val==2){
            res = evaluateLeft | evaluateRight;
        }else if(root->val==3){
            res = evaluateLeft & evaluateRight;
        }

        return res;
    }
public:
    bool evaluateTree(TreeNode* root) {

        return helper(root);
        
    }
};