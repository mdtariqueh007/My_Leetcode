class DSU{
    private:
    vector<int> parent;
    vector<int> size;
    vector<int> values;

    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        values.resize(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
            values[i] = -1;
        }
    }

    int findParent(int u){
        if(parent[u]==u){
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v, int val){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv){
            values[pu] &= val;
            return;
        }

        if(size[pu]>=size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
            values[pu] &= values[pv];
            values[pu] &= val;
        }
        else{

            parent[pu] = pv;
            size[pv] += size[pu];
            values[pv] &= values[pu];
            values[pv] &= val;

        }
    }

    int getCompValue(int u){
        int pu = findParent(u);

        return values[pu];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        DSU ds(n);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int val = it[2];

            ds.Union(u, v, val);
        }

        vector<int> ans;

        for(auto q: query){
            int s = q[0];
            int t = q[1];

            int ps = ds.findParent(s);
            int pt = ds.findParent(t);

            if(ps==pt){
                ans.push_back(ds.getCompValue(ps));
            }else{
                ans.push_back(-1);
            }
        }

        return ans;



    }
};