class Solution {
    private:
    void dfs(int ancestor,int node,vector<int> adj[],vector<vector<int>>&ans){
        // visited[node] = 1;

        // ans[node] = ancestors;

        

        for(auto it : adj[node]){
            if(ans[it].empty() || ans[it].back()!=ancestor){
                ans[it].push_back(ancestor);
                dfs(ancestor,it,adj,ans);
                
            }
        }

        // ancestors.pop_back();
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);

        vector<int> adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        // vector<int> visited(n,0);
        

        for(int i = 0;i<n;i++){
            
                dfs(i,i,adj,ans);

        }

        return ans;


        
    }
};