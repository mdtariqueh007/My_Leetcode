class Solution {
    private:
    void dfs(int node,vector<int> adj[],vector<int>&vis,int &n,int &m){
        vis[node] = 1;

        n++;
        m += adj[node].size();

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,n,m);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int res = 0;

        vector<int> vis(n,0);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int n = 0,m = 0;
                dfs(i,adj,vis,n,m);
                // cout<<n<<" "<<m<<"\n";
                int edges = (n*(n-1));

                if(edges==m){
                    res++;
                }
                
            }
        }

        return res;

    }
};