class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int maxRow = -1;
        int minRow = n;
        int maxCol = -1;
        int minCol = m;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    minRow = min(minRow,i);
                    minCol = min(minCol,j);

                    maxRow = max(maxRow,i);
                    maxCol = max(maxCol,j);

                }
            }
        }

        int area = (maxRow - minRow + 1) * (maxCol - minCol + 1);

        return area;
        
    }
};