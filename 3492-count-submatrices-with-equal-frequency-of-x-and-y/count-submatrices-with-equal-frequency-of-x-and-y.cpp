class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> countX(m,vector<int>(n,0));
        vector<vector<int>> countY(m,vector<int>(n,0));

        for(int i = 0;i<m;i++){
            if(grid[i][0]=='X'){
                countX[i][0] = 1;
            }
            else if(grid[i][0]=='Y'){
                countY[i][0] = 1;
            }
        }

        for(int i  = 0;i<m;i++){
            for(int j = 1;j<n;j++){
                countX[i][j] += countX[i][j-1] + (grid[i][j]=='X');
                countY[i][j] += countY[i][j-1] + (grid[i][j]=='Y');
            }
        }

        int ans = 0;

        for(int j = 0;j<n;j++){
            int sum1 = 0, sum2 = 0;

            for(int row = 0;row<m;row++){
                sum1 += countX[row][j];
                sum2 += countY[row][j];

                if(sum1>0  && sum1==sum2){
                    ans++;
                }
            }
        }

        return ans;
        
    }
};