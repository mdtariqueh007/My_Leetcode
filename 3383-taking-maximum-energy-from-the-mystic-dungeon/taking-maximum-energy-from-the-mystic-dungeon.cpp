class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();

        vector<int> dp(n,0);

        int ans = -1e9;

        for(int i = n-1;i>=0;i--){
            dp[i] = energy[i];
            if(i+k<n){
                dp[i] += dp[i+k];
            }

            ans = max(ans,dp[i]);
        }

        return ans;

    }
};