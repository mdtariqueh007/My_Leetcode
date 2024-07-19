class Solution {
    private:
    int helper(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()-1) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int minJumps = 1e9;
        for(int i = 1;i<=nums[ind];i++){
            int jumps = 1 + helper(ind+i,nums,dp);
            minJumps = min(minJumps,jumps);
        }

        return dp[ind] = minJumps;
    }
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        // vector<int> dp(n,0);

        // dp[n-1] = 0;
        // for(int i = n-2;i>=0;i--){
        //     int minJumps = 1e9;
        //     for(int j = 1;j<=nums[i];j++){
        //         if(i+j<n) minJumps = min(minJumps,1 + dp[i+j]);
        //     }
        //     dp[i] = minJumps;
        // }

        // return dp[0];

        int jumps = 0;

        int l = 0, r = 0;

        while(r<n-1){
            int farthest = 0;

            for(int i  = l ;i<=r;i++){
                farthest = max(farthest,  i + nums[i]);
            }

            l = r + 1;
            r = farthest;

            jumps++;
        }

        return jumps;

        // return helper(0,nums,dp);
        
    }
};