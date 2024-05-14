class Solution {
    private int maxGold(int i,int j,int[][] grid){
        int m = grid.length;
        int n = grid[0].length;

        if(i<0 || j<0 || i==m || j==n || grid[i][j]==0){
            return 0;
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        int temp = grid[i][j];
        grid[i][j] = 0;

        int ans = 0;

        for(int k = 0;k<4;k++){
            ans = Math.max(ans,maxGold(i+dx[k],j+dy[k],grid));
        }

        grid[i][j] = temp;

        return ans+temp;


    }
    public int getMaximumGold(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]>0){
                    ans = Math.max(ans,maxGold(i,j,grid));
                }
            }
        }

        return ans;
        
    }
}