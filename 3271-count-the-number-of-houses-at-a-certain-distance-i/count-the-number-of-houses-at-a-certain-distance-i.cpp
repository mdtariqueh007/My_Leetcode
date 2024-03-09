class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {

        vector<vector<int>> mat(n+1,vector<int>(n+1,1e9));

        for(int i = 1;i<=n-1;i++){
            mat[i][i+1] = 1;
            mat[i+1][i] = 1;
        }

        mat[x][y] = 1;
        mat[y][x] = 1;

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i==j){
                    mat[i][j] = 0;
                }
            }
        }

        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        vector<int> ans(n,0);

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(mat[i][j]>=1 && mat[i][j]<=n){
                    ans[mat[i][j]-1]++;
                }
            }
        }

        return ans;


        
    }
};