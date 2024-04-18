class Solution {
    private:
    int dfs(vector<vector<int>>&grid,int row,int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0) return 1;
        if(grid[row][col]==-1){
            return 0;
        }

        grid[row][col] = -1;

        int p = 0;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        for(int i = 0;i<4;i++){
            p += dfs(grid,row+dx[i],col + dy[i]);
        }

        return p;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    return dfs(grid,i,j);
                }
            }
        }

        return 0;

        

        
    }
};