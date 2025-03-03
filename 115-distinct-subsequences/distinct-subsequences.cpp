class Solution {
    private:
    int dp[1001][1001];
    int solve(int i, int j, string& s, string& t){
        if(i==s.length()){
            if(j==t.length()){
                return 1;
            }

            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            int take = solve(i + 1, j + 1, s, t);
            int notTake = solve(i + 1, j, s, t);

            return dp[i][j] = take + notTake;
        }
        else{
            int notTake = solve(i+1, j, s, t);

            return dp[i][j] = notTake;
        }
    }
public:
    int numDistinct(string s, string t) {

        memset(dp, -1, sizeof(dp));

        return solve(0,0,s,t);
        
    }
};