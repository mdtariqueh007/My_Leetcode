class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);

        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int prev = 0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    if(dp[i]<1+dp[prev]){
                        dp[i] = dp[prev] + 1;
                        hash[i] = prev;
                    }
                }
            }
        }

        int res = -1;
        int lastIndex = -1;
        for(int i=0; i<=n-1; i++){
            if(dp[i]> res){
                res= dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(),ans.end());

        return ans;

        
    }
};