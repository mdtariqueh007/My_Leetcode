class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {

        vector<int> ans;

        map<int,int> mp;

        int n = nums.size();

        for(auto it  : nums){
            for(int x : it){
                mp[x]++;
                if(mp[x]==n){
                    ans.push_back(x);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;

        


        
    }
};