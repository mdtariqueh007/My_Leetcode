class DSU{
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};


class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        DSU ds(n);

        vector<int> adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        map<int,vector<int>> val_to_nodes;

        for(int i = 0;i<n;i++){
            val_to_nodes[vals[i]].push_back(i);
        }

        int res = n;

        vector<bool> isActive(n,false);

        for(auto &it : val_to_nodes){
            vector<int> nodes = it.second;

            for(int u  :nodes){
                for(int v  :adj[u]){
                    if(isActive[v]){
                        ds.unionByRank(u,v);
                    }
                }
                isActive[u] = true;
            }


            vector<int> parents;
            for(int u : nodes)
            {
                parents.push_back(ds.find(u));
            }

            int sz = parents.size();

            sort(parents.begin(),parents.end());

            for(int i = 0;i<sz;i++){
                int curr = parents[i];
                int count = 0;

                while(i<sz && curr==parents[i]){
                    i++;
                    count++;
                }
                i--;
                res += (count * (count - 1))/2;
            }

        }

        return res;



        
    }
};