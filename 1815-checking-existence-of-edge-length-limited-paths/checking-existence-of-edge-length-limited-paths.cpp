class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return;

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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU ds(n);

        for(int i = 0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        sort(queries.begin(),queries.end(),[&](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });

        sort(edgeList.begin(),edgeList.end(),[&](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });

        int j = 0;

        vector<bool> ans(queries.size());

        for(auto q: queries){
            int u = q[0];
            int v = q[1];
            int t = q[2];
            int ind = q[3];

            while(j<edgeList.size() && edgeList[j][2]<t){
                ds.unionBySize(edgeList[j][0],edgeList[j][1]);
                j++;
            }

            ans[ind] = (ds.find(u)==ds.find(v));
        }

        return ans;
    }
};