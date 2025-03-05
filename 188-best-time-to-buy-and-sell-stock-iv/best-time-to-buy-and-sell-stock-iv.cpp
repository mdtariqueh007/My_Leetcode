class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<int> buy(k+1, -1e9), sell(k+1, 0);

        for(int i = 0;i<n;i++){
            for(int j = 1;j<=k;j++){
                buy[j] = max(buy[j], -prices[i] + sell[j-1]);
                sell[j] = max(sell[j], prices[i] + buy[j]);
            }
        }

        return sell[k];
        
    }
};