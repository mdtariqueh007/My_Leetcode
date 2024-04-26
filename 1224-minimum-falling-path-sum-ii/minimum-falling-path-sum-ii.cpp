class Solution {
    private:
    int dp[201][202];
    int f(int i,int prevCol,vector<vector<int>>&grid){
        if(i>=grid.size()){
            return 0;
        }

        if(dp[i][prevCol+1]!=-1){
            return dp[i][prevCol+1];
        }

        int ans = 1e9;

        for(int j = 0;j<grid[0].size();j++){
            if(j!=prevCol){
                ans = min(ans, grid[i][j] + f(i+1,j,grid));
            }
        }

        return dp[i][prevCol+1] = ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,grid);
    }
};