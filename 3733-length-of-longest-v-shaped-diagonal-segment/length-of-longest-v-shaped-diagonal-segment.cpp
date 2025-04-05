class Solution {
    private:
    int dy[4] = {1, 1, -1, -1};
    int dx[4] = {-1, 1, 1, -1};

    int dfs(int i, int j, int k, int targetVal, bool turned, vector<vector<int>>&grid){
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || grid[ni][nj]!=targetVal){
            return 1;
        }

        int takeStraightPath = 1 + dfs(ni, nj, k, 2 - targetVal, turned, grid);
        int takeTurn = 0;
        if(!turned){
            takeTurn = 1 + dfs(ni, nj, (k+1)%4, 2 - targetVal, true, grid);
        }

        return max(takeStraightPath, takeTurn);
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k = 0;k<4;k++){
                        ans = max(ans, dfs(i, j, k, 2, false, grid));
                    }
                }
            }
        }

        return ans;
        
    }
};