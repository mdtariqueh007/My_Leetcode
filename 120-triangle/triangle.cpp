class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        // memset(dp,-1,sizeof(dp));

        // return solve(0, 0, triangle);

        int n = triangle.size();

        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        vector<int> dp(n+1, 0);

        for(int j = n - 1;j>=0;j--){
            dp[j] = triangle[n-1][j];
        }

        // for(auto it: dp){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";

        // for(int i = n - 2;i>=0;i--){
        //     dp[i][n-1] = triangle[i][n-1] + dp[i+1][n-1];
        // }

        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                int moveDown = triangle[i][j] + dp[j];
                int moveDiag = triangle[i][j] + dp[j+1];

                dp[j] = min(moveDown, moveDiag);
            }

        //     for(auto it: dp){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        }

        // for(auto it: dp){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";

        return dp[0];
        
    }
};