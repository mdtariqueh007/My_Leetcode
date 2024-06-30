class DSU{
    
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i<n;i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int node){
        if(node==parent[node]){
            return node;
        }

        return find(parent[node]);
    }

    void unionByRank(int u,int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU==rootV) return;

        if(rank[rootU]<rank[rootV]){
            parent[rootU] = rootV;
        }
        else if(rank[rootV]<rank[rootU]){
            parent[rootV] = rootU;
        }
        else{
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU Ads(n);
        DSU Bds(n);

        sort(edges.begin(),edges.end(),greater<>());

        int res = edges.size();

        for(auto it : edges){
            int u = --it[1];
            int v = --it[2];

            int type = it[0];

            if(type==3){
                if(Ads.find(u)!=Ads.find(v) || Bds.find(u)!=Bds.find(v)){
                    res--;
                }
                Ads.unionByRank(u,v);
               
                Bds.unionByRank(u,v);
                
            }
            else if(type==2){
                if(Bds.find(u)!=Bds.find(v)){
                    Bds.unionByRank(u,v);
                    res--;
                }
            }
            else{
                if(Ads.find(u)!=Ads.find(v)){
                    Ads.unionByRank(u,v);
                    res--;
                }
            }
        }

        int c1 = 0, c2 = 0;

        for(int i = 0;i<n;i++){
            if(Ads.parent[i]==i){
                c1++;
            }
            if(Bds.parent[i]==i){
                c2++;
            }
        }

        if(c1==1 && c2==1){
            return res;
        }

        return -1;


        
    }
};