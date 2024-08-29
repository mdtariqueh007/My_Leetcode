class DSU{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }

        DSU ds(maxRow + maxCol + 2);
        unordered_map<int,int> stoneNodes;
        for(auto it : stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            ds.unionBySize(row,col);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1; 
        }

        int cnt = 0;


        for(auto it : stoneNodes){
            if(ds.findPar(it.first)==it.first){
                cnt++;
            }
        }

        return stones.size() - cnt;
    }
};