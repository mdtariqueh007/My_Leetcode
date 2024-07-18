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
    void buildGraph(TreeNode* node,TreeNode* parent,unordered_map<TreeNode*,vector<TreeNode*>>&adj,vector<TreeNode*>&leaves){
        if(node==NULL){
            return;
        }

        if(node->left==NULL && node->right==NULL){
            leaves.push_back(node);
        }

        if(parent!=NULL){
            adj[parent].push_back(node);
            adj[node].push_back(parent);
        }

        buildGraph(node->left,node,adj,leaves);
        buildGraph(node->right,node,adj,leaves);
    }
    int bfs(unordered_map<TreeNode*,vector<TreeNode*>>&adj,TreeNode* source,int dis){
        queue<pair<int,TreeNode*>> q;
        unordered_set<TreeNode*> visited;

        q.push({0,source});
        visited.insert(source);

        int cnt = 0;

        while(!q.empty()){

            int d = q.front().first;
            TreeNode* node = q.front().second;

            q.pop();

            if(node!=source && node->left==NULL && node->right==NULL){
                if(d<=dis){
                    cnt++;
                }
            }

            if(d>dis){
                break;
            }

            for(auto it : adj[node]){
                if(visited.find(it)==visited.end()){
                    q.push({d+1,it});
                    visited.insert(it);
                }
            }

        }

        return cnt;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        
        unordered_map<TreeNode*,vector<TreeNode*>> adj;
        vector<TreeNode*> leaves;

        buildGraph(root,NULL,adj,leaves);

        int cnt = 0;

        for(TreeNode* node : leaves){
            cnt += bfs(adj,node,distance);
        }

        return cnt/2;
    }
};