class Solution {
    // private:
    // int dp[2502][2502];
    // int solve(int curr, int prev, vector<int>&nums){
    //     if(curr==nums.size()){
    //         return 0;
    //     }

    //     if(dp[curr][prev+1]!=-1){
    //         return dp[curr][prev+1];
    //     }

    //     int take = 0, notTake = 0;

    //     if(prev==-1 || nums[curr]>nums[prev]){

    //         take = 1 + solve(curr+1, curr, nums);

    //     }

    //     notTake = solve(curr+1, prev, nums);

    //     return dp[curr][prev+1] = max(take, notTake);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, -1, nums);

        int n = nums.size();

        vector<int> dp(n, 1);

        int maxi = 1;

        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxi = max(maxi, dp[i]);
                }
            }
        }

        return maxi;


        
    }
};