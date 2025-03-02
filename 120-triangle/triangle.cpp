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

        memset(dp,-1,sizeof(dp));

        return solve(0, 0, triangle);
        
    }
};