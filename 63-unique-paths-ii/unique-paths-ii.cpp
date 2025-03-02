class Solution {
   
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, 0, obstacleGrid);

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n,0));

        dp[m-1][n-1] = obstacleGrid[m-1][n-1]==1?0:1;

        for(int i = m-2;i>=0;i--){
            dp[i][n-1] = obstacleGrid[i][n-1]==1?0:dp[i+1][n-1];
        }

        for(int j = n - 2;j>=0;j--){
            dp[m-1][j] = obstacleGrid[m-1][j]==1?0:dp[m-1][j+1];
        }

        for(int i = m - 2;i>=0;i--){
            for(int j = n - 2;j>=0;j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                else{
                    int moveRight = dp[i][j+1];
                    int moveDown = dp[i+1][j];

                    dp[i][j] = (moveDown*1LL + moveRight*1LL);
                }
            }
        }

        return dp[0][0];
        
    }
};