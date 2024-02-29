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
    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            int prev = level%2?1e9:-1;
            for(int i = 0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();

                int currVal = node->val;

                if(level%2==0){
                    if(currVal%2==0 || currVal<=prev){
                        return false;
                    }
                    prev = currVal;
                }
                else{
                    if(currVal%2 || currVal>=prev){
                        return false;
                    }
                    prev = currVal;
                }

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }

        return true;
        
    }
};