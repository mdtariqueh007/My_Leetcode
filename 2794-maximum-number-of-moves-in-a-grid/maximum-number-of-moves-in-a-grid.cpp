class Solution {
    private:
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        int maxi = 0;

        for(int dx = -1;dx<=1;dx++){
            int nRow = row + dx;
            int nCol = col + 1;

            if(nRow>=0 && nCol>=0 && nRow<grid.size() && nCol<grid[0].size() && grid[nRow][nCol]>grid[row][col]){
                maxi = max(maxi,1 + solve(nRow,nCol,grid,dp));
            }
        }

        return dp[row][col] = maxi;
       
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        int maxi = 0;

        for(int i = 0;i<m;i++){
            int curr = solve(i,0,grid,dp);

            maxi = max(maxi,curr);
        }

        return maxi;


    }
};