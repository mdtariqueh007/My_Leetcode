class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> cellHeights(m, vector<int>(n,-1));

        queue<pair<int,int>> q;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isWater[i][j]){
                    q.push({i,j});
                    cellHeights[i][j] = 0;
                }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        int heightOfNextLayer = 1;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int i = 0;i<4;i++){
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];

                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && cellHeights[nrow][ncol]==-1){
                        cellHeights[nrow][ncol] = heightOfNextLayer;
                        q.push({nrow, ncol});
                    }
                }
            }

            heightOfNextLayer++;
        }

        return cellHeights;

        
        
    }
};