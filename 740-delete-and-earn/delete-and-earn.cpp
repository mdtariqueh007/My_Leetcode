class Solution {
    private:
    int dp[10001];
    int solve(int num, unordered_map<int,int>&mp){
        if(num<=0){
            return 0;
        }

        if(num==1){
            return mp[num];
        }

        if(dp[num]!=-1){
            return dp[num];
        }

        int take = num * mp[num] + solve(num-2, mp);
        int notTake = solve(num - 1, mp);

        return dp[num] = max(take, notTake);
    }
public:
    int deleteAndEarn(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        int maxNum = 0;

        for(int x: nums){
            mp[x]++;
            maxNum = max(maxNum, x);
        }

        memset(dp, -1, sizeof(dp));

        return solve(maxNum, mp);



        
        
    }
};