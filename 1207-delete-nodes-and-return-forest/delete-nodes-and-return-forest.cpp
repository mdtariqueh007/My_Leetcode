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
    TreeNode* helper(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>&ans){
        if(root==NULL){
            return NULL;
        }

        root->left = helper(root->left,st,ans);
        root->right = helper(root->right,st,ans);

        if(st.find(root->val)!=st.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }

            return NULL;
        }
        else{
            return root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        unordered_set<int> toDel(to_delete.begin(),to_delete.end());

        root = helper(root,toDel,ans);

        if(root!=NULL){
            ans.push_back(root);
        }

        return ans;
    }
};