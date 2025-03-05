class Solution {
    // private:
    // int dp[5001][2];
    // int solve(int day, bool buy, vector<int>&prices){
    //     if(day>=prices.size()){
    //         return 0;
    //     }

    //     if(dp[day][buy]!=-1){
    //         return dp[day][buy];
    //     }

    //     int noTransaction = solve(day+1, buy, prices);

    //     if(buy){
    //         int buyStock = -prices[day] + solve(day+1, false, prices);

    //         return dp[day][buy] = max(noTransaction, buyStock);
    //     }
    //     else{
    //         int sellStock = prices[day] + solve(day+2, true, prices);

    //         return dp[day][buy] = max(noTransaction, sellStock);
    //     }
    // }
public:
    int maxProfit(vector<int>& prices) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, true, prices);

        int n = prices.size();

        // vector<vector<int>> dp(n+2, vector<int>(2,0));

        vector<vector<int>> dp(3, vector<int>(2,0));

        for(int i = n - 1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                if(buy){
                    dp[i%3][buy] = max(dp[(i+1)%3][buy], -prices[i]+dp[(i+1)%3][1-buy]);
                }
                else{
                    dp[i%3][buy] = max(dp[(i+1)%3][buy], prices[i]+dp[(i+2)%3][1-buy]);
                }
            }
        }

        return dp[0][1];
        
    }
};