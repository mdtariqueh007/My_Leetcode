class Solution {
    // private:
    // int dp[100001][2][3];
    // int solve(int day, bool buy, int cap, vector<int>& prices){
    //     if(cap==0){
    //         return 0;
    //     }
    //     if(day==prices.size()){
    //         return 0;
    //     }

    //     if(dp[day][buy][cap]!=-1){
    //         return dp[day][buy][cap];
    //     }

    //     if(buy){
    //         int dontBuy = solve(day+1, buy, cap, prices);
    //         int buyStock = -prices[day] + solve(day+1, false, cap, prices);

    //         return dp[day][buy][cap] = max(dontBuy, buyStock);
    //     }
    //     else{
    //         int dontSell = solve(day+1, buy, cap, prices);
    //         int sellStock = prices[day] + solve(day+1, true, cap-1, prices);

    //         return dp[day][buy][cap] = max(dontSell, sellStock);
    //     }


    // }
public:
    int maxProfit(vector<int>& prices) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, true, 2, prices);

        int n = prices.size();

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3,0)));


        for(int i = n - 1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i%2][buy][cap] = max(dp[(i+1)%2][buy][cap], -prices[i]+dp[(i+1)%2][1-buy][cap]);
                    }
                    else{
                        dp[i%2][buy][cap] = max(dp[(i+1)%2][buy][cap], prices[i]+dp[(i+1)%2][1-buy][cap-1]);
                    }
                }
            }
        }

        return dp[0][1][2];
        
    }
};