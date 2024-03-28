class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cntFresh = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2) {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1) cntFresh++;
            }
        }
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int tmax = 0;
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tmax = t;
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
            }

        }

        if(cnt!=cntFresh) return -1;
        return tmax;
        
    }
};