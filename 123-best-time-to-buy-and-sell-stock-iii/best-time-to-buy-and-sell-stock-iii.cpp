class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy1 = -1e9, sell1 = 0, buy2 = -1e9, sell2 = 0;

        int n = prices.size();

        for(int i = 0;i<n;i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }

        return sell2;
        
    }
};