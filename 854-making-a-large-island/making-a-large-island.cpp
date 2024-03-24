class DSU{
   
    public:
    vector<int> size, parent;
    DSU(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);

        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }


    }

    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu==pv){
            return;
        }

        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DSU ds(n*n);

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0) continue;

                for(int k = 0;k<4;k++){
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                        int node = i*n + j;
                        int adjNode = nr*n + nc;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }

        int maxi = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1) continue;
                unordered_set<int> comp;
                for(int k = 0;k<4;k++){
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                        int node = i*n + j;
                        int adjNode = nr*n + nc;
                        comp.insert(ds.findUPar(adjNode));
                    }
                }
                int curr = 1;

                for(auto it : comp){
                    curr += ds.size[it];
                }

                maxi = max(maxi,curr);
            }
        }

        for(int i = 0;i<n*n;i++){
            maxi = max(maxi,ds.size[i]);
        }

        return maxi;


        
    }
};