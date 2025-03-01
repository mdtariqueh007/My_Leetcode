class Solution {
public:
    int tribonacci(int n) {

        if(n==0 || n==1){
            return n;
        } 

        if(n==2){
            return 1;
        }

        // vector<int> dp(n+1,0);

        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 1;

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;

        for(int i = 3;i<=n;i++){
            // dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            int curr = prev1 + prev2 + prev3;

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
        
    }
};