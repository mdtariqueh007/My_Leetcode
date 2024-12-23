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
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);

        int ans = 0;

        while(!q.empty()){
            int sz = q.size();

            vector<int> currNodes;

            for(int i = 0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();

                currNodes.push_back(curr->val);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

                
            }

            vector<pair<int,int>> temp;

            for(int i = 0;i<currNodes.size();i++){
                temp.push_back({currNodes[i], i});
            }

            sort(temp.begin(), temp.end());

            int swaps = 0;

            for(int i = 0;i<temp.size();i++){
                if(temp[i].second==i){
                    continue;
                }
                else{
                    swaps++;
                    swap(temp[i], temp[temp[i].second]);
                    i--;
                }
            }

            ans += swaps;


        }

        return ans;

    }
};