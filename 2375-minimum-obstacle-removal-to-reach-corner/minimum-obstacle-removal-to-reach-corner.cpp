class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dis(m,vector<int>(n,1e9));

        dis[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({dis[0][0], 0, 0});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!pq.empty()){

            vector<int> vec = pq.top();
            pq.pop();

            int obstacles = vec[0];
            int row = vec[1];
            int col = vec[2];

            if(row==m-1 && col==n-1){
                return obstacles;
            }

            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];


                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int newObstacles = obstacles + grid[nrow][ncol];

                    if(newObstacles<dis[nrow][ncol]){
                        dis[nrow][ncol] = newObstacles;

                        pq.push({newObstacles, nrow, ncol});
                    }
                }
            }

           

            


        }

         return dis[m-1][n-1];

    }
};