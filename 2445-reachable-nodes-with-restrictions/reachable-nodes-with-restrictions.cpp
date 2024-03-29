class Solution {
    private:
    // int cnt = 0;
    void dfs(int node,vector<int> adj[],vector<int>&vis,unordered_set<int>&st,int&cnt){
        if(st.find(node)!=st.end()){
            return;
        }

        vis[node] = 1;
        cnt++;

        
        for(auto it : adj[node]){
            if(!vis[it]){
                
                dfs(it,adj,vis,st,cnt);

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

        int cnt = 0;

        dfs(0,adj,vis,dead,cnt);

        // int cnt = 0;

        // for(int i : vis){
        //     if(i==1){
        //         cnt++;
        //     }
        // }

        return cnt;


        
    }
};