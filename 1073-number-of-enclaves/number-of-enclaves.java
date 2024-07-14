class Solution {
    private void dfs(int i,int j,int[][]grid,int[][]vis){
        if(i<0 || j<0 || i>=grid.length || j>=grid[0].length || grid[i][j]==0 || vis[i][j]==1) return;

        vis[i][j] = 1;

        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }
    public int numEnclaves(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int[][] vis = new int[m][n];

        for(int i = 0;i<m;i++){
            if(vis[i][0]==0 && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            if(vis[i][n-1]==0 && grid[i][n-1]==1){
                dfs(i,n-1,grid,vis);
            }
        }

        for(int j = 0;j<n;j++){
            if(vis[0][j]==0 && grid[0][j]==1){
                dfs(0,j,grid,vis);
            }
            if(vis[m-1][j]==0 && grid[m-1][j]==1){
                dfs(m-1,j,grid,vis);
            }
        }

        int cnt = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
}