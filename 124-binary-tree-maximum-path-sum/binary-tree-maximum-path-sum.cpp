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
    int findMaxPathSum(TreeNode* root,int& maxi){
        if(root==NULL) return 0;

        int leftPathSum = findMaxPathSum(root->left,maxi);
        int rightPathSum = findMaxPathSum(root->right,maxi);

        if(leftPathSum<0) leftPathSum = 0;
        if(rightPathSum<0) rightPathSum = 0;

        int val = root->val;

        maxi = max(maxi,leftPathSum+rightPathSum+val);

        return val + max(leftPathSum,rightPathSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        findMaxPathSum(root,maxi);

        return maxi;
    }
};