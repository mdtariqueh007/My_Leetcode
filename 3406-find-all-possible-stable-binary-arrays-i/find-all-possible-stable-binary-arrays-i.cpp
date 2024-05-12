class Solution {
    private:
    // int dp[201][201][3][201];
    const int mod = 1e9+7;
    long long solve(int zero,int one,int prev,int limit,vector<vector<vector<int>>>&dp){
        if(zero==0 && one==0){
            return 1;
        }

        if(zero<0 || one<0){
            return 0;
        }

        if(dp[zero][one][prev]!=-1){
            return dp[zero][one][prev];
        }

        long long ans = 0;

        if(prev!=0){
            for(int cnt = 1;cnt<=min(zero,limit);cnt++){
                ans = (ans + solve(zero-cnt,one,0,limit,dp))%mod;
            }
        }

        if(prev!=1){
            for(int cnt = 1;cnt<=min(one,limit);cnt++){
                ans = (ans + solve(zero,one-cnt,1,limit,dp))%mod;
            }
        }

        return dp[zero][one][prev]= ans%mod;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        // memset(dp,-1,sizeof(dp));

        // long long ans = solve(zero,one,2,0,limit);

        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1,vector<int>(3,-1)));
        long long ans = solve(zero,one,2,limit,dp);

        return ans%mod;
        
    }
};