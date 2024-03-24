class Solution {
    private:
    void dfs(int node,vector<int> adj[],vector<int>&vis,unordered_set<int>&st){
        if(st.find(node)!=st.end()){
            return;
        }

        vis[node] = 1;

        
        for(auto it : adj[node]){
            if(!vis[it]){
                
                dfs(it,adj,vis,st);

            }
        }

        
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<int> adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_set<int> dead(restricted.begin(),restricted.end());

        

        vector<int> vis(n,0);

        dfs(0,adj,vis,dead);

        int cnt = 0;

        for(int i : vis){
            if(i==1){
                cnt++;
            }
        }

        return cnt;


        
    }
};