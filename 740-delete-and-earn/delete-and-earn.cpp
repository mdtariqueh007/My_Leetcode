class Solution {
   
public:
    int deleteAndEarn(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        int maxNum = 0;

        for(int x: nums){
            mp[x]++;
            maxNum = max(maxNum, x);
        }

        // memset(dp, -1, sizeof(dp));

        // return solve(maxNum, mp);

        vector<int> dp(maxNum+1, 0);

        dp[0] = 0;
        dp[1] = mp[1];

        

        for(int i = 2;i<=maxNum;i++){
            int take = i * mp[i] + dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake); 

        }

        return dp[maxNum];



        
        
    }
};