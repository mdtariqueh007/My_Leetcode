class Solution {
    private:
    int dp[50001][2];
    int solve(int day, int buy, vector<int>&prices, int fee){
        if(day>=prices.size()){
            return 0;
        }

        if(dp[day][buy]!=-1){
            return dp[day][buy];
        }

        if(buy){

            int dontBuyStock = solve(day+1, buy, prices, fee);
            int buyStock = -prices[day] + solve(day+1, false, prices, fee);

            return dp[day][buy] = max(dontBuyStock, buyStock);

        }
        else{
            int dontSellStock = solve(day+1, buy, prices, fee);
            int sellStock = prices[day] - fee + solve(day+1, true, prices, fee);

            return dp[day][buy] = max(dontSellStock, sellStock);
        }


    }
public:
    int maxProfit(vector<int>& prices, int fee) {

        memset(dp, -1, sizeof(dp));

        return solve(0, true, prices, fee);
        
    }
};