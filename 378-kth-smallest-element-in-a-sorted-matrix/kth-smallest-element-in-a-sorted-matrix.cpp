class Solution {
    private:
    int countNonBigger(int target, vector<vector<int>>&matrix){
        int n = matrix.size();
        int i = n - 1;
        int j = 0;
        int cnt = 0;

        while(i>=0 && j<n){
            if(matrix[i][j]>target){
                i--;
            }
            else{
                cnt += (i+1);
                j++;
            }
        }

        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        int ans = high;

        
        while(low<=high){
            int mid = low + (high - low)/2;

            int cnt = countNonBigger(mid, matrix);

            if(cnt<k){
                
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;

    }
};