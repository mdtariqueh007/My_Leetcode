class Solution {
    // private int[] dp = new int[46];
    // private int helper(int i,int n){
    //     if(i==n-1){
    //         return 1;
    //     }
    //     if(i==n-2){
    //         return 2;
    //     }

    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }

    //     return dp[i] = helper(i+1,n) + helper(i+2,n);
    // }
    public int climbStairs(int n) {
        // Arrays.fill(dp,-1);
        // return helper(0,n);

        if(n==0 || n==1){
            return n;
        }

        int[] dp = new int[n+1];
        Arrays.fill(dp,0);

        dp[n-1] = 1;
        dp[n-2] = 2;

        for(int i = n-3;i>=0;i--){
            dp[i] = dp[i+1] + dp[i+2];
        }

        return dp[0];
    }
}