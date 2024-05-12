class Solution {
    private:
    // int dp[201][201][3][201];
    const int mod = 1e9+7;
    long long solve(int zero,int one,int prev,int cnt,int limit,vector<vector<vector<vector<int>>>>&dp){
        if(zero==0 && one==0){
            return 1;
        }

        if(zero<0 || one<0){
            return 0;
        }

        if(dp[zero][one][prev][cnt]!=-1){
            return dp[zero][one][prev][cnt];
        }

        long long ans = 0;

        if(zero>0){
            if(prev==0 && cnt<limit){
                ans = (ans + solve(zero-1,one,0,cnt+1,limit,dp))%mod;
            }
            else if(prev==1 || cnt==0){
                ans = (ans + solve(zero-1,one,0,1,limit,dp))%mod;
            }
        }

        if(one>0){
            if(prev==1 && cnt<limit){
                ans = (ans + solve(zero,one-1,1,cnt+1,limit,dp))%mod;
            }
            else if(prev==0 || cnt==0){
                ans = (ans + solve(zero,one-1,1,1,limit,dp))%mod;
            }
        }

        return dp[zero][one][prev][cnt] = ans%mod;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        // memset(dp,-1,sizeof(dp));

        // long long ans = solve(zero,one,2,0,limit);

        vector<vector<vector<vector<int>>>>dp(zero+1,vector<vector<vector<int>>>(one+1, vector<vector<int>>(3,vector<int>(limit+1,-1))));
        long long ans = solve(zero,one,2,0,limit,dp);

        return ans%mod;
        
    }
};