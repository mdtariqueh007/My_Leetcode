class Solution {
    
public:
    int deleteAndEarn(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }


        sort(nums.begin(), nums.end());

        vector<int> dp(n+1, 0);

        for(int ind = n - 1;ind>=0;ind--){
            int take = nums[ind] * mp[nums[ind]];
            int newValidIndex = ind + mp[nums[ind]] + mp[nums[ind]+1];

            if(newValidIndex<=n){
                take += dp[newValidIndex];
            } 

            int notTake = 0;
            if(ind+mp[nums[ind]]<=n){
                notTake += dp[ind+mp[nums[ind]]];
            }

            dp[ind] = max(take, notTake);
        }

        return dp[0];
        
    }
};