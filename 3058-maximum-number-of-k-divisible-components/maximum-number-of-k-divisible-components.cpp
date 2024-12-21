class Solution {
    private:
    int components = 0;
    int dfs(int node,int parent,vector<int>&values,vector<int> adj[],int k){
        long long val = values[node];
        for(auto adjNode : adj[node]){
            if(adjNode==parent){
                continue;
            }
            
            int rec = dfs(adjNode,node,values,adj,k);
            val += rec;
            
            if(rec==0){
                components++;
            }
        }
        return val%k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<int> adj[n];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        
        
        
        dfs(0,-1,values,adj,k);
        
        return components+1;
        
        
        
        
        
        
        
    }
};