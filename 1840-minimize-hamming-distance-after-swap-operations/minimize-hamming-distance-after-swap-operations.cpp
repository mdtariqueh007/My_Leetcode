class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node==parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv){
            return;
        }

        if(size[pu]<size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else{
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        DSU ds(n);

        for(auto it : allowedSwaps){
            ds.unionBySize(it[0],it[1]);
        }

        vector<multiset<int>> mt(n);

        for(int i = 0;i<n;i++){
            mt[ds.find(i)].insert(source[i]);
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            int p = ds.find(i);

            if(mt[p].find(target[i])==mt[p].end()){
                cnt++;
            }
            else{
                mt[p].erase(mt[p].find(target[i]));
            }
        }

        return cnt;
    }
};