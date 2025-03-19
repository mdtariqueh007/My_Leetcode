class DSU{
    private:
    vector<int> parent;
    vector<int> size;
    
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv){
            return;
        }

        if(size[pu]>=size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        DSU ds(m*n);

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1'){
                    int parentVal = i * n + j;

                    for(int k = 0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]=='1'){
                            int newVal = ni * n + nj;

                            ds.Union(parentVal, newVal);
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1' && ds.find(i * n + j)==(i * n + j)){
                    ans++;
                }
            }
        }

        return ans;

        

        return ans;
        
    }
};