class Solution {
    // private:
    // int dp[50001][2];
    // int solve(int day, int buy, vector<int>&prices, int fee){
    //     if(day>=prices.size()){
    //         return 0;
    //     }

    //     if(dp[day][buy]!=-1){
    //         return dp[day][buy];
    //     }

    //     if(buy){

    //         int dontBuyStock = solve(day+1, buy, prices, fee);
    //         int buyStock = -prices[day] + solve(day+1, false, prices, fee);

    //         return dp[day][buy] = max(dontBuyStock, buyStock);

    //     }
    //     else{
    //         int dontSellStock = solve(day+1, buy, prices, fee);
    //         int sellStock = prices[day] - fee + solve(day+1, true, prices, fee);

    //         return dp[day][buy] = max(dontSellStock, sellStock);
    //     }


    // }
public:
    int maxProfit(vector<int>& prices, int fee) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, true, prices, fee);


        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int i = n - 1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[i][buy] = max(dp[i+1][buy], -prices[i] + dp[i+1][1-buy]);
                }
                else{
                    dp[i][buy] = max(dp[i+1][buy], prices[i]-fee + dp[i+1][1-buy]);
                }
            }
        }

        return dp[0][1];
        
    }
};