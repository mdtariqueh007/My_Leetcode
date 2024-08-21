class Solution {
    private:
    int f(int i,int j,string&s,vector<vector<int>>&dp){
        if(i==j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int minTurns = INT_MAX;
        for(int k = i;k<j;k++){
            int firstPart = f(i,k,s,dp);
            int secondPart = f(k+1,j,s,dp);

            minTurns = min(minTurns,firstPart+secondPart);
        }
        if(s[i]==s[j]) return dp[i][j] = minTurns-1;
        else return dp[i][j] = minTurns;
    }
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);
    }
};