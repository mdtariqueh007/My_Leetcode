class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 1;j<n;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        for(int sc = 0;sc<n;sc++){
            for(int ec = sc;ec<n;ec++){
                for(int sr = 0;sr<m;sr++){
                    int sum = 0;

                    for(int er = sr;er<m;er++){
                        sum += matrix[er][ec] - (sc>0?matrix[er][sc-1]:0);

                        if(sum==target){
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};