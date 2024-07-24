class Solution {
    private:
    unordered_map<int,vector<int>> cops;
    unordered_map<int,vector<pair<int,int>>> ancestors;
    void dfs(vector<int>&nums,vector<vector<int>>&adj,int src,int parent,int level,vector<int>&ans){
        int maxLevel = -1;
        for(auto cop : cops[nums[src]]){
            auto it = ancestors[cop];
            if(!it.empty() && it.back().first>maxLevel){
                maxLevel = it.back().first;
                ans[src] = it.back().second;
            }
        }

        ancestors[nums[src]].push_back({level,src});

        for(auto child : adj[src]){
            if(child!=parent){
                dfs(nums,adj,child,src,level+1,ans);
            }
        }
        ancestors[nums[src]].pop_back();
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(int x : nums){
            st.insert(x);
        }

        for(int x1 : st){
            for(int x2 : st){
                if(__gcd(x1,x2)==1){
                    cops[x1].push_back(x2);
                }
            }
        }

        int n = nums.size();

        vector<vector<int>> adj(n);
        vector<int> ans(n,-1);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(nums,adj,0,0,0,ans);

        return ans;
    }
};