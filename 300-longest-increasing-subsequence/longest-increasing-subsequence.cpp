class Solution {
    private:
    int dp[2502][2502];
    int solve(int curr, int prev, vector<int>&nums){
        if(curr==nums.size()){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }

        int take = 0, notTake = 0;

        if(prev==-1 || nums[curr]>nums[prev]){

            take = 1 + solve(curr+1, curr, nums);

        }

        notTake = solve(curr+1, prev, nums);

        return dp[curr][prev+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, nums);
        
    }
};