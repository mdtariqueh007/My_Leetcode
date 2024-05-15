class DSU{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU ds(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            int pu = ds.findUPar(u);
            int pv = ds.findUPar(v);

            if(pu==pv){
                return it;
            }else{
                ds.unionBySize(u,v);
            }
        }

        return {};


    }
};