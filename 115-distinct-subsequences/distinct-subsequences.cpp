class Solution {
    // private:
    // int dp[1001][1001];
    // int solve(int i, int j, string& s, string& t){
    //     if(j==t.length()){
    //         return 1;
    //     }
    //     if(i==s.length()){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     if(s[i]==t[j]){
    //         int take = solve(i + 1, j + 1, s, t);
    //         int notTake = solve(i + 1, j, s, t);

    //         return dp[i][j] = take + notTake;
    //     }
    //     else{
    //         int notTake = solve(i+1, j, s, t);

    //         return dp[i][j] = notTake;
    //     }
    // }
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        if (m < n) return 0;

        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));

        
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
};