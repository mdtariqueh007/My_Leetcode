class Solution {
    private:
    int dp[100001][2][3];
    int solve(int day, bool buy, int cap, vector<int>& prices){
        if(cap==0){
            return 0;
        }
        if(day==prices.size()){
            return 0;
        }

        if(dp[day][buy][cap]!=-1){
            return dp[day][buy][cap];
        }

        if(buy){
            int dontBuy = solve(day+1, buy, cap, prices);
            int buyStock = -prices[day] + solve(day+1, false, cap, prices);

            return dp[day][buy][cap] = max(dontBuy, buyStock);
        }
        else{
            int dontSell = solve(day+1, buy, cap, prices);
            int sellStock = prices[day] + solve(day+1, true, cap-1, prices);

            return dp[day][buy][cap] = max(dontSell, sellStock);
        }


    }
public:
    int maxProfit(vector<int>& prices) {

        memset(dp, -1, sizeof(dp));

        return solve(0, true, 2, prices);
        
    }
};