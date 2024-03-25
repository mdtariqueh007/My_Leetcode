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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU ds(n);

        unordered_map<string,int> mapMail;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMail.find(mail)==mapMail.end()){
                    mapMail[mail] = i;
                }else{
                    ds.unionBySize(i,mapMail[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it : mapMail){
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};