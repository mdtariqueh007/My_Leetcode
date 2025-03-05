class Solution {
    private:
    int dp[5001][2];
    int solve(int day, bool buy, vector<int>&prices){
        if(day>=prices.size()){
            return 0;
        }

        if(dp[day][buy]!=-1){
            return dp[day][buy];
        }

        int noTransaction = solve(day+1, buy, prices);

        if(buy){
            int buyStock = -prices[day] + solve(day+1, false, prices);

            return dp[day][buy] = max(noTransaction, buyStock);
        }
        else{
            int sellStock = prices[day] + solve(day+2, true, prices);

            return dp[day][buy] = max(noTransaction, sellStock);
        }
    }
public:
    int maxProfit(vector<int>& prices) {

        memset(dp, -1, sizeof(dp));

        return solve(0, true, prices);
        
    }
};