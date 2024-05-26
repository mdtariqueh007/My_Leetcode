class Solution {
    private:
    long long dp[100001][2][3];
    const int mod = 1e9 + 7;
    int helper(int n,int absent,int late){
        if(absent>=2 || late>=3){
            return 0;
        }

        if(dp[n][absent][late]!=-1){
            return dp[n][absent][late];
        }

        if(n==0){
            return 1;
        }

        long long s_present = helper(n-1,absent,0);
        long long s_absent = helper(n-1,absent + 1,0);
        long long s_late = helper(n-1,absent,late + 1);

        return dp[n][absent][late] = (s_present%mod + s_absent%mod + s_late%mod)%mod;
    }
public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n,0,0);
    }
};