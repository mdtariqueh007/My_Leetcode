class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        // vector<vector<int>> dp(m, vector<int>(n,0));

        vector<int> prev(n,0);

        int maxi = 0;

        // for(int i = 0;i<m;i++){
        //     if(matrix[i][0]=='1'){
        //         dp[i][0] = 1;
        //         maxi = 1;
        //     }
        // }

        if(matrix[0][0]=='1'){
            prev[0] = 1;
            maxi = 1;
        }

        for(int j = 1;j<n;j++){
            if(matrix[0][j]=='1'){
                prev[j] = 1;
                maxi = 1;
            }
        }

        for(int i = 1;i<m;i++){
            vector<int> curr(n,0);
            if(matrix[i][0]=='1'){
                curr[0] = 1;
                maxi = max(maxi, curr[0]);
            }
            for(int j = 1;j<n;j++){

                if(matrix[i][j]=='1'){

                curr[j] = 1 + min(prev[j], min(prev[j-1], curr[j-1]));

                maxi = max(maxi, curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }

            prev = curr;
        }

        return maxi * maxi;

    }
};