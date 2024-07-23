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

    int find(int node){
        if(node==parent[node]) return node;

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        DSU ds(n);

        for(auto it : pairs){
            ds.unionBySize(it[0],it[1]);
        }

        vector<multiset<char>> mt(n);

        for(int i = 0;i<n;i++){
            mt[ds.find(i)].insert(s[i]);
        }

        string ans;

        for(int i = 0;i<n;i++){
            int p = ds.find(i);

            ans.push_back(*mt[p].begin());

            mt[p].erase(mt[p].begin());
        }

        return ans;
    }
};