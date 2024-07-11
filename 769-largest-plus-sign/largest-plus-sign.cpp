class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> grid(n,vector<int>(n,1));

        for(auto it : mines){
            grid[it[0]][it[1]] = 0;
        }

        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> right(n,vector<int>(n,0));
        vector<vector<int>> up(n,vector<int>(n,0));
        vector<vector<int>> bottom(n,vector<int>(n,0));

        for(int i = 0;i<n;i++){
            left[i][0] = grid[i][0]; 
        }

        for(int i = 0;i<n;i++){
            right[i][n-1] = grid[i][n-1];
        }

        for(int j = 0;j<n;j++){
            up[0][j] = grid[0][j];
        }

        for(int j = 0;j<n;j++){
            bottom[n-1][j] = grid[n-1][j];
        }


        for(int i = 0;i<n;i++){
            for(int j = 1;j<n;j++){
                if(grid[i][j]==1)
                left[i][j] = left[i][j-1] + grid[i][j];
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = n-2;j>=0;j--){
                if(grid[i][j]==1)
                right[i][j] = right[i][j+1] + grid[i][j];
            }
        }

        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1)
                up[i][j] = up[i-1][j] + grid[i][j];
            }
        }

        for(int i = n - 2;i>=0;i--){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1)
                bottom[i][j] = bottom[i+1][j] + grid[i][j];
            }
        }

        int maxi = 0;

       

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0) continue;


                if(j-1>=0 && j+1<n && i-1>=0 && i+1<n){
                    maxi = max(maxi,1 + min({left[i][j-1],right[i][j+1],up[i-1][j],bottom[i+1][j]}));
                    // cout<<i<<" "<<j<<"    "<<maxi<<"\n";
                }
                else{
                    maxi = max(maxi,1);
                }
            }
        }

        

        return maxi;
        
    }
};