class Solution {
    private:
    // int dp[201][201][3][201];
    const int mod = 1e9+7;
    // long long solve(int zero,int one,int prev,int limit,vector<vector<vector<int>>>&dp){
    //     if(zero==0 && one==0){
    //         return 1;
    //     }

    //     if(zero<0 || one<0){
    //         return 0;
    //     }

    //     if(dp[zero][one][prev]!=-1){
    //         return dp[zero][one][prev];
    //     }

    //     long long ans = 0;

    //     if(prev!=0){
    //         for(int cnt = 1;cnt<=min(zero,limit);cnt++){
    //             ans = (ans + solve(zero-cnt,one,0,limit,dp))%mod;
    //         }
    //     }

    //     if(prev!=1){
    //         for(int cnt = 1;cnt<=min(one,limit);cnt++){
    //             ans = (ans + solve(zero,one-cnt,1,limit,dp))%mod;
    //         }
    //     }

    //     return dp[zero][one][prev]= ans%mod;
    // }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1,vector<int>(3,0)));
        // long long ans = solve(zero,one,2,limit,dp);

        for(int i = 1;i<=min(zero,limit);i++){
            dp[i][0][0] = 1;
        }
        for(int j = 1;j<=min(one,limit);j++){
            dp[0][j][1] = 1; 
        }


        for(int i = 1;i<=zero;i++){
            for(int j = 1;j<=one;j++){
                dp[i][j][0] = (dp[i-1][j][1] + dp[i-1][j][0])%mod;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%mod;

                if(i>limit){
                    dp[i][j][0] = (dp[i][j][0] - dp[i-1-limit][j][1] + mod)%mod;
                }
                if(j>limit){
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-1-limit][0] + mod)%mod;
                }
            }
        }

        long long ans = (dp[zero][one][0] + dp[zero][one][1])%mod;

        return ans%mod;
    }
};