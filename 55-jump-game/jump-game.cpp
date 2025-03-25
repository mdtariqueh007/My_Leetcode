class Solution {
   
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 2);
        dp[n-1] = 1;

        for(int i = n - 2;i>=0;i--){
            int maxPos = min(i + nums[i], n - 1);

            for(int j = maxPos;j>=i+1;j--){
                if(dp[j]==1){
                    dp[i] = 1;
                    break;
                }
            }

           
        }

        return dp[0]==1;
        
    }
};