class Solution {
    private:
    int f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
        if(i==s1.size()){
            int cost = 0;
            for(int ind = j;ind<s2.size();ind++){
                cost += s2[ind];
            }
            return cost;
        }
        if(j==s2.size()){
            int cost = 0;
            for(int ind = i;ind<s1.size();ind++){
                cost += s1[ind];
            }
            return cost;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = f(i+1,j+1,s1,s2,dp);
        }
        else{
            int delFrom1 = s1[i] + f(i+1,j,s1,s2,dp);
            int delFrom2 = s2[j] + f(i,j+1,s1,s2,dp);
            int delFromBoth = s1[i]+s2[j] + f(i+1,j+1,s1,s2,dp);

            return dp[i][j] = min(delFrom1,min(delFrom2,delFromBoth));
        }



    }
public:
    int minimumDeleteSum(string s1, string s2) {

        int m = s1.length(),n = s2.length();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int j = 0;j<=n;j++){
            int cost = 0;
            for(int ind = j;ind<n;ind++){
                cost += s2[ind];
            }
            dp[m][j] = cost;
        }

        for(int i = 0;i<=m;i++){
            int cost = 0;
            for(int ind = i;ind<m;ind++){
                cost += s1[ind];
            }

            dp[i][n] = cost;
        }

        for(int i = m - 1;i>=0;i--){
            for(int j = n - 1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int deleteFrom1 = s1[i] + dp[i+1][j];
                    int deleteFrom2 = s2[j] + dp[i][j+1];
                    int deleteFromBoth = s1[i] + s2[j] + dp[i+1][j+1];

                    dp[i][j] = min(deleteFrom1, min(deleteFrom2, deleteFromBoth));
                }
            }
        }

        return dp[0][0];



        // return f(0,0,s1,s2,dp);
        
    }
};