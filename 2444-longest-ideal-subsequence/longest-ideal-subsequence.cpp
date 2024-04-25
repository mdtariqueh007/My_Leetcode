class Solution {
    private:
    int dp[100001][123];
    int f(string& s,int k,int i,char prev){
        if(i>=s.length()){
            return 0;
        }

        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }

        int take = 0;
        if(abs(prev - s[i])<=k || prev=='$'){
            take = 1 + f(s,k,i+1,s[i]);
        }
        int notTake = f(s,k,i+1,prev);

        return dp[i][prev] = max(take,notTake);
    }
public:
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return f(s,k,0,'$');
    }
};