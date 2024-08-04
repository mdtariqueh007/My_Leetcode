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
    void inorder(TreeNode* root,vector<int>&temp){
        if(root==NULL){
            return;
        }

        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> temp;

        inorder(root,temp);

        int i = 0;
        int j = temp.size() - 1;

        while(i<j){
            int sum = temp[i] + temp[j];

            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
    }
};