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
public:
    int sumOfLeftLeaves(TreeNode* root) {

        int sum= 0;
        if(root==NULL){
            return sum;
        }
        queue<pair<TreeNode*,bool>> q;
        q.push({root,0});
        while(q.empty()==false){
            int count = q.size();
            for(int i = 0;i<count;i++){
                TreeNode* curr = q.front().first;
                bool isLeftChild = q.front().second;
                q.pop();
                if(curr->left==NULL && curr->right==NULL && isLeftChild){
                    sum += curr->val;
                }
                if(curr->left) q.push({curr->left,1});
                if(curr->right) q.push({curr->right,0});
            }
        }

        return sum;
        
    }
};