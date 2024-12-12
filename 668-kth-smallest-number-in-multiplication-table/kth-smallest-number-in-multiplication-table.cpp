class Solution {
    private:
    int countNonBigger(int target, int m, int n){
        int i = m - 1, j = 0;

        int cnt = 0;

        while(i>=0 && j<n){
            if((i+1)*(j+1)>target){
                i--;
            }
            else{
                cnt += i + 1;
                j++;
            }
        }

        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        
        int low = 1, high = m * n;

        while(low<=high){
            int mid = low + (high - low)/2;

            int cnt = countNonBigger(mid,m,n);

            if(cnt<k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;

    }
};