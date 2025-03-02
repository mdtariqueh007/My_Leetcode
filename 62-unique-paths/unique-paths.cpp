class Solution {

public:
    int uniquePaths(int m, int n) {

        // vector<vector<int>> dp(m+1, vector<int>(n+1,1));

        // dp[m-1][n-1] = 1;

        vector<int> next(n+1 ,1);
        vector<int> curr(n+1, 1);

        for(int i = m - 2;i>=0;i--){
            for(int j = n - 2;j>=0;j--){
                int moveRight = curr[j+1];
                int moveDown = next[j];

                curr[j] = moveRight + moveDown;

                next = curr;
            }
        }

        return next[0];
    }
};