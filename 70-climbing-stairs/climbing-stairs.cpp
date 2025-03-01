class Solution {
    private:
    int memo[46];
    int solve(int curr, int n){
        if(curr>n){
            return 0;
        }

        if(curr==n){
            return 1;
        }

        if(memo[curr]!=-1){
            return memo[curr];
        }

        int oneStep = solve(curr+1, n);
        int twoSteps = solve(curr+2, n);

        return memo[curr] = oneStep + twoSteps;
    }
public:
    int climbStairs(int n) {
        // memset(memo, -1 , sizeof(memo));
        // return solve(0, n);


        if(n==1 || n==2){
            return n;
        }

        vector<int> dp(n+1, 0);

        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};