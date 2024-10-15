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
    int dfs(TreeNode* root, vector<int>&sizes){
        if(root==NULL){
            return 0;
        }

        int left = dfs(root->left,sizes);
        int right = dfs(root->right, sizes);

        int cntNodes = -1;

        if(left==right){
            cntNodes = (left + right + 1);
            sizes.push_back(cntNodes);
        }

        return cntNodes;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;

        dfs(root,sizes);

        sort(sizes.rbegin(),sizes.rend());

        if(k>sizes.size()){
            return -1;
        }

        return sizes[k-1];



        
    }
};