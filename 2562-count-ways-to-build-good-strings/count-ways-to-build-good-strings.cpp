class Solution {
    private:
    int dp[200001];
    const int mod = 1e9 + 7;
    long long f(int low,int high,int zero,int one,int len){
        if(len>high){
            return 0;
        }

        if(dp[len]!=-1){
            return dp[len];
        }

        int ans = 0;

        if(len>=low && len<=high){
            ans = 1;
        }

        ans = (ans%mod + f(low,high,zero,one,len+zero)%mod + f(low,high,zero,one,len+one)%mod)%mod;

        return dp[len] = ans%mod;  
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {

        memset(dp,-1,sizeof(dp));

        return f(low,high,zero,one,0);
        
    }
};