class Solution {
    private:

    long long dp[100001][2][2];
    long long solve(int ind,vector<int>&nums,int isStarted,int sign){
        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][isStarted][sign]!=-1){
            return dp[ind][isStarted][sign];
        }

        long long ans = -1e15;

        if(isStarted==0){
            ans = max(ans, nums[ind] + solve(ind+1,nums,1,1));
        }
        else{
            if(sign==0){
                ans = max(ans, nums[ind] + solve(ind+1,nums,1,1));
                ans = max(ans, solve(ind,nums,0,0));
            }
            else{
                ans = max(ans, -nums[ind] + solve(ind + 1,nums,1,0));
                ans = max(ans, solve(ind,nums,0,0));
            }
        }

        return dp[ind][isStarted][sign] = ans;
    }
public:
    long long maximumTotalCost(vector<int>& nums) {

        memset(dp,-1,sizeof(dp));
        return solve(0,nums,0,0);
    }
};