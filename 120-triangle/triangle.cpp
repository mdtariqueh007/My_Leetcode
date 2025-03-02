class Solution {
    private:
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>&triangle){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int moveDown = triangle[i][j] + solve(i+1, j, triangle);
        int moveDiag = triangle[i][j] + solve(i+1, j+1, triangle);

        return dp[i][j] = min(moveDown, moveDiag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        // memset(dp,-1,sizeof(dp));

        // return solve(0, 0, triangle);

        int n = triangle.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int j = n - 1;j>=0;j--){
            dp[n-1][j] = triangle[n-1][j];
        }

        // for(int i = n - 2;i>=0;i--){
        //     dp[i][n-1] = triangle[i][n-1] + dp[i+1][n-1];
        // }

        for(int i = n-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                int moveDown = triangle[i][j] + dp[i+1][j];
                int moveDiag = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(moveDown, moveDiag);
            }
        }

        return dp[0][0];
        
    }
};