class Solution {
    private:
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size()){
            return 1e9;
        }

        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[grid.size()-1][grid[0].size()-1];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int moveRight = grid[i][j] + solve(i, j+1, grid);
        int moveDown = grid[i][j] + solve(i+1, j, grid);

        return dp[i][j] = min(moveRight, moveDown);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        memset(dp, -1, sizeof(dp));

        return solve(0,0, grid);
        
    }
};