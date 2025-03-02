class Solution {
public:
    int uniquePaths(int m, int n) {

        int N = m+n-2;
        int R = min(m,n) - 1;
        long long ans = 1;
        for(int i = 1;i<=R;i++){
            ans = ((long long)ans*(N-i+1))/i;
        }

        return ans;
        
    }
};