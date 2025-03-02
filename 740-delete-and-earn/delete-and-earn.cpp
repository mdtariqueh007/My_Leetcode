class Solution {
    private:
    int dp[20001];
    int solve(int ind, vector<int>&nums, unordered_map<int, int>&mp){

        if(ind>=nums.size()){
            return 0;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int take = nums[ind] * mp[nums[ind]];
        int newValidIndex = ind + mp[nums[ind]] + mp[nums[ind]+1];
        take += solve(newValidIndex, nums, mp);

        int notTake = solve(ind+mp[nums[ind]], nums, mp);

        return dp[ind] = max(take, notTake);

    }
public:
    int deleteAndEarn(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }


        sort(nums.begin(), nums.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, nums, mp);
        
    }
};