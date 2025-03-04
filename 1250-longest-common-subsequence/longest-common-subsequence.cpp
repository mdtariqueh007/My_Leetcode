class Solution {
    private:
    // int dp[1001][1001];
    // int solve(int i, int j, string& text1, string& text2){
    //     if(i==text1.size() || j==text2.size()){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     if(text1[i]==text2[j]){
    //         return dp[i][j] = 1 + solve(i+1, j+1, text1, text2);
    //     }
    //     else{
    //         int moveFrom1 = solve(i+1, j, text1, text2);
    //         int moveFrom2 = solve(i, j+1, text1, text2);

    //         return dp[i][j] = max(moveFrom1, moveFrom2);
    //     }
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, 0, text1, text2);

        int n = text1.size(), m = text2.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        vector<int> dp(m+1, 0), dpNext(m+1,0);

        for(int i = n - 1;i>=0;i--){
            for(int j = m - 1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[j] = 1 + dpNext[j+1];
                }
                else{
                    dp[j] = max(dpNext[j], dp[j+1]);
                }
            }

            dpNext = dp;
        }

        return dp[0];
        
    }
};