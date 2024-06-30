class Solution {
    int[][] dp = new int[301][11];
    private int solve(int []jd,int ind,int d){
        if(ind>=jd.length){
            return 0;
        }

        if(dp[ind][d]!=-1){
            return dp[ind][d];
        }

        int maxi = jd[ind];

        if(d==1){
            for(int i = ind;i<jd.length;i++){
                maxi = Math.max(maxi,jd[i]);
            }

            return dp[ind][d] = maxi;
        }

        int res = (int)1e9;
        for(int i = ind;i<=jd.length - d;i++){
            maxi = Math.max(maxi,jd[i]);

            int ans = maxi + solve(jd,i+1,d - 1);

            res = Math.min(res,ans);
        }

        return dp[ind][d] = res;
    }
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;

        if(n<d){
            return -1;
        }

        for(int []row : dp){
            Arrays.fill(row,-1);
        }

        return solve(jobDifficulty,0,d);
    }
}