class Solution {
    
public:
    int minDistance(string word1, string word2) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, 0, word1, word2);

        int n = word1.size();
        int m = word2.size();

        if(n==0){
            return m;
        }

        if(m==0){
            return n;
        }

        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        vector<int> dp(m+1, 0);
        vector<int> dpNext(m+1, 0);

        for(int j = 0;j<=m;j++){
            dpNext[j] = m - j;
        }


       


        for(int i = n - 1;i>=0;i--){
            dp[m] = n - i;
            for(int j = m - 1;j>=0;j--){
                
                if(word1[i]==word2[j]){
                    dp[j] = dpNext[j+1];
                }
                else{
                    int insertOp = 1 + dp[j+1];
                    int deleteOp = 1 + dpNext[j];
                    int replaceOp = 1 + dpNext[j+1];

                    dp[j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
            dpNext = dp;
        }

        return dpNext[0];


        
    }
};