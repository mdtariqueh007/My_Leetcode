class Solution {
   
public:
    int minPathSum(vector<vector<int>>& grid) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0,0, grid);

        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        vector<int> dp(n+1);

        dp[n-1] = grid[m-1][n-1];

        for(int j = n - 2;j>=0;j--){
            dp[j] = grid[m-1][j] + dp[j+1];
        }

        for(int i = m-2;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int moveRight = grid[i][j] + (j+1<n?dp[j+1]:1e9);
                int moveDown = grid[i][j] + dp[j];

                dp[j] = min(moveRight, moveDown);
            }
        }

        return dp[0];


        
    }
};