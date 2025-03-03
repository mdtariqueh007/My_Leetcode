class Solution {
    
public:
    int minimumDeleteSum(string s1, string s2) {

        int m = s1.length(),n = s2.length();

        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        vector<int> dp(n+1,0), dpNext(n+1,0);

        for(int j = 0;j<=n;j++){
            int cost = 0;
            for(int ind = j;ind<n;ind++){
                cost += s2[ind];
            }
            dpNext[j] = cost;
        }

        

        for(int i = m - 1;i>=0;i--){
            int cost = 0;
            for(int ind = i;ind<m;ind++){
                cost += s1[ind];
            }

            dp[n] = cost;
            for(int j = n - 1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[j] = dpNext[j+1];
                }
                else{
                    int deleteFrom1 = s1[i] + dpNext[j];
                    int deleteFrom2 = s2[j] + dp[j+1];
                    int deleteFromBoth = s1[i] + s2[j] + dpNext[j+1];

                    dp[j] = min(deleteFrom1, min(deleteFrom2, deleteFromBoth));
                }
            }

            dpNext = dp;
        }

        return dp[0];



        // return f(0,0,s1,s2,dp);
        
    }
};