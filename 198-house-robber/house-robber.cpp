class Solution {
    private:
    int dp[101];
    int solve(int curr, vector<int>&nums){
        if(curr>=nums.size()){
            return 0;
        }

        if(dp[curr]!=-1){
            return dp[curr];
        }

        int rob = nums[curr] + solve(curr+2, nums);
        int dontRob = solve(curr+1, nums);

        return dp[curr] = max(rob, dontRob);
    }
public:
    int rob(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return solve(0, nums);
        
    }
};