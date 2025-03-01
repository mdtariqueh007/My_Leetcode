class Solution {
    
public:
    int rob(vector<int>& nums) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, nums);

        int n = nums.size();

        vector<int> dp(n+2, 0);

        for(int i = n-1;i>=0;i--){
            int rob = nums[i] + dp[i+2];
            int dontRob = dp[i+1];

            dp[i] = max(rob, dontRob);
        }

        return dp[0];
        
    }
};