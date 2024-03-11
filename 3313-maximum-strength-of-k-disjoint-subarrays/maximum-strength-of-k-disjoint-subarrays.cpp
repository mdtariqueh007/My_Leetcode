class Solution {

    private:
    vector<vector<vector<long long>>> dp;
    long long solve(int ind,int k,vector<int>&nums,bool startNew){

        if(k==0){
            return 0;
        }

        if(ind>=nums.size()){
            return -1e18;
        }

        if(dp[ind][k][startNew]!=-1){
            return dp[ind][k][startNew];
        }

        long long notTake = -1e18;
        
        if(startNew){

            notTake = solve(ind+1,k,nums,true);
        }
        long long takeNew = solve(ind+1,k-1,nums,true) + 1LL*nums[ind]*k*(k%2?1:-1);
        long long takeContinue = solve(ind+1,k,nums,false) + 1LL*nums[ind]*k*(k%2?1:-1);

        return dp[ind][k][startNew] = max(max(notTake,takeNew),takeContinue);
    }

public:
    long long maximumStrength(vector<int>& nums, int k) {

        dp.resize(nums.size()+1,vector<vector<long long>>(k+1,vector<long long>(2,-1)));

        return solve(0,k,nums,true);
        
    }
};