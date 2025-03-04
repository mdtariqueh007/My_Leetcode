class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, 0));

        int ans = 1;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                int diff = nums[i] - nums[j] + 500;

                if(dp[j][diff]>0){
                    dp[i][diff] = dp[j][diff] + 1;
                }
                else{
                    dp[i][diff] = 2;
                }

                ans = max(ans, dp[i][diff]);
            }
            
        }

        return ans;
        
    }
};