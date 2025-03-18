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
    vector<int> ans;
    void helper(TreeNode* root, int level){
        if(root==NULL){
            return ;
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }

        if(root->right){
            helper(root->right, level+1);
        }
        if(root->left){
            helper(root->left, level+1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {

        helper(root, 0);

        return ans;
        
    }
};