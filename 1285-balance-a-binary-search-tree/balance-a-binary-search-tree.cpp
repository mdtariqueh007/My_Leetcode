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
    void dfs(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }

        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
    TreeNode* buildBST(int l,int r,vector<int>&arr){
        if(l>r){
            return NULL;
        }

        int mid = l+ (r - l)/2;

        TreeNode* newNode = new TreeNode(arr[mid]);
        newNode->left = buildBST(l,mid-1,arr);
        newNode->right = buildBST(mid+1,r,arr);

        return newNode;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> arr;

        dfs(root,arr);

        int l = 0;
        int r = arr.size() - 1;

        return buildBST(l,r,arr);


        
    }
};