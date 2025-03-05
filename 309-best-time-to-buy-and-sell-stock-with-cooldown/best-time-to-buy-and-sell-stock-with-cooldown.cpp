class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> reset(n, 0), held(n, 0), sold(n, 0);

        reset[0] = 0;
        held[0] = -prices[0];
        sold[0] = -1e9;

        for(int i = 1;i<n;i++){
            sold[i] = held[i-1] + prices[i];
            held[i] = max(held[i-1], reset[i-1] - prices[i]);
            reset[i] = max(reset[i-1], sold[i-1]);
        }

        return max(sold.back(), reset.back());




        
    }
};