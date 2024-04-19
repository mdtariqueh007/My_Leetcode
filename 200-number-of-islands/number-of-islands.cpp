class Solution {
    private:
    void bfs(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&grid){
        vis[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int dx[4] = {0,0,-1,1};
            int dy[4] = {-1,1,0,0};
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                   q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,0));

        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }

        return count;
        
    }
};