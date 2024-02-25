class DisjointSet{
    private:
    vector<int> parent,size;
    int numComponents;
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        numComponents = n;
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int parentU = findUPar(u);
        int parentV = findUPar(v);

        if(parentU==parentV){
            return;
        }
        
        if(size[parentU]<size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV]; 
        }

        numComponents -= 1;

    }

    int getComponents(){
        return numComponents;
    }


};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        DisjointSet dsu(n);

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            for(int fac = 2;fac*fac<=nums[i];fac++){
                if(nums[i]%fac!=0){
                    continue;
                }
                if(mp.find(fac)==mp.end()){
                    mp[fac] = i;
                }
                else{
                    dsu.unionBySize(mp[fac],i);
                }
                while(nums[i]%fac==0){
                    nums[i] = nums[i]/fac;
                }
            }

            if(nums[i]>1){
                if(mp.find(nums[i])==mp.end()){
                    mp[nums[i]] = i;
                }
                else{
                    dsu.unionBySize(mp[nums[i]],i);
                }
            }
        }

        int numOfComp = dsu.getComponents();

        if(numOfComp==1){
            return true;
        }

        return false;
    }
};