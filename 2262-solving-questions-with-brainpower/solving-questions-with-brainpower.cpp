class Solution {
    // private:
    // long long dp[100001];
    // long long helper(int ind, vector<vector<int>>& questions){
    //     if(ind>=questions.size()){
    //         return 0;
    //     }

    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }

    //     long long solve = questions[ind][0] + helper(ind + questions[ind][1] + 1, questions);
    //     long long skip = helper(ind + 1, questions);

    //     return dp[ind] = max(solve, skip);
    // }
public:
    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();

        vector<long long> dp(n+1, 0);

        for(int i = n - 1;i>=0;i--){
            long long solve = questions[i][0], skip = 0;

            if(i + questions[i][1] + 1<n){
                solve += dp[i + questions[i][1] + 1];
            }

            skip += dp[i+1];

            dp[i] = max(solve, skip);

        }

        return dp[0];
        
    }
};