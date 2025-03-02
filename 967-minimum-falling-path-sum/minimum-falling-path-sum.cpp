class Solution {
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int ans = 1e9;

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int j = 0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i = n - 2;i>=0;i--){
            for(int j = 0;j<n;j++){
                int moveDown = matrix[i][j] + dp[i+1][j];
                int moveLeftDiag = matrix[i][j] + (j-1>=0?dp[i+1][j-1]:1e9);
                int moveRightDiag = matrix[i][j] + (j+1<n?dp[i+1][j+1]:1e9);

                dp[i][j] = min(moveDown, min(moveLeftDiag, moveRightDiag));
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
        
    }
};