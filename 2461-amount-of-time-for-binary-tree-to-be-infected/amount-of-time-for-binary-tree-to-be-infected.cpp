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
    void makeGraph(TreeNode* root, int parent, unordered_map<int,unordered_set<int>>&adj){
        if(root==NULL){
            return;
        }
        if(parent!=-1){
            adj[root->val].insert(parent);
        }

        if(root->left){
            adj[root->val].insert(root->left->val);
        }
        if(root->right){
            adj[root->val].insert(root->right->val);
        }

        makeGraph(root->left,root->val,adj);
        makeGraph(root->right,root->val,adj);
    }
public:
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<int,unordered_set<int>> adj;

        makeGraph(root, -1, adj);

        queue<int> q;

        unordered_set<int> visited;

        q.push(start);

        visited.insert(start);

        int time = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int node = q.front();
                q.pop();

                for(int it : adj[node]){
                    if(visited.find(it)==visited.end()){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }

            time++;
        }

        return time - 1;




        
    }
};