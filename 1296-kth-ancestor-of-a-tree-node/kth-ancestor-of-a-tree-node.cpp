class TreeAncestor {
    private:
    vector<vector<int>> up;
    int LOG;

    void dfs(int node,int par,vector<int> adj[]){
        up[node][0] = par;

        for(int i = 1;i<LOG;i++){
            if(up[node][i-1]!=-1){
                up[node][i] = up[up[node][i-1]][i-1];
            }            
        }

        for(int child : adj[node]){
            dfs(child,node,adj);
        }
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
     LOG = 0;
     while(1<<(LOG)<=n){
        LOG++;
     }
     up = vector<vector<int>>(n,vector<int>(LOG,-1));  

     vector<int> adj[n];

     for(int i = 1;i<parent.size();i++){
        adj[parent[i]].push_back(i);
     }

     dfs(0,-1,adj);


    }
    
    int getKthAncestor(int node, int k) {
        for(int i = LOG-1;i>=0;i--){
            if(k&(1<<i)){
                node = up[node][i];

                if(node==-1){
                    return -1;
                }

                k = k - (1<<i);
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */