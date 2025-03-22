class DSU{
    private:
    vector<int> parent, size, edges;

    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        edges.resize(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
            edges[i] = 0;
        }
    }

    int find(int u){
        if(parent[u]==u){
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv){
            edges[pu]++;
            return;
        }

        if(size[pu]>=size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
            edges[pu] += edges[pv] + 1;
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
            edges[pv] += edges[pu] + 1;
        }
    }

    int getEdges(int u){
        return edges[u];
    }

    int getNodes(int u){
        return size[u];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DSU ds(n);

        for(auto it: edges){
            ds.Union(it[0], it[1]);
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            if(ds.find(i)==i){
                int nodeCount = ds.getNodes(i);
                int edgesCount = ds.getEdges(i);

                if(i==1){
                    cout<<edgesCount<<" "<<nodeCount<<"\n";
                }

                if(edgesCount == (nodeCount * (nodeCount - 1))/2){
                    if(i==1){
                        cout<<"YES\n";
                    }
                    ans++;
                }
            }
        }

        return ans;
        
    }
};