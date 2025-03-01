class Solution {
    
public:
    int rob(vector<int>& nums) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, nums);

        int n = nums.size();

        // vector<int> dp(n+2, 0);

        // dp[n+1] = 0;
        // dp[n] = 0;

        int next2 = 0;
        int next1 = 0;

        for(int i = n-1;i>=0;i--){
            int rob = nums[i] + next2;
            int dontRob = next1;

            int curr = max(rob, dontRob);

            next2 = next1;
            next1 = curr;
        }

        return next1;
        
    }
};