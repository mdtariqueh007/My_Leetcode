class Solution {
    private:
    int dfs(int node,vector<int> adj[],vector<int>& informTime){
        int ans = 0;

        

        for(int it : adj[node]){
            
            ans = max(ans, informTime[node] + dfs(it,adj,informTime));
            
        }

        

        return ans;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<int> adj[n];

        for(int i = 0;i<n;i++){
            int v = i;
            int u = manager[i];
            if(u!=-1)
                adj[u].push_back(v);
        }

        int ans = dfs(headID,adj,informTime);

        return ans;
        
    }
};