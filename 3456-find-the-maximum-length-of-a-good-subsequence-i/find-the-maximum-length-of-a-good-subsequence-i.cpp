class Solution {
    private:
    int dp[501][501][26];
    int solve(int ind,int prev,int k,vector<int>&nums){
        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][prev][k]!=-1){
            return dp[ind][prev][k];
        }

        int pick = 0,notPick = 0;

        

        if(prev==500 || nums[ind]==nums[prev]){
            
            pick = 1 + solve(ind+1,ind,k,nums);
            notPick = solve(ind+1,prev,k,nums);

        }

        else if(nums[ind]!=nums[prev]){
            if(k>0){
                pick = 1 + solve(ind+1,ind,k-1,nums);
            }
            notPick = solve(ind+1,prev,k,nums);
        }

        return dp[ind][prev][k] = max(pick, notPick);
    }
public:
    int maximumLength(vector<int>& nums, int k) {

        memset(dp,-1,sizeof(dp));
        return solve(0,500,k,nums);
    }
};