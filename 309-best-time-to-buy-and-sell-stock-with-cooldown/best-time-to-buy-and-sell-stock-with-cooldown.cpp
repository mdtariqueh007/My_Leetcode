class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // vector<int> reset(n, 0), held(n, 0), sold(n, 0);

        // reset[0] = 0;
        // held[0] = -prices[0];
        // sold[0] = -1e9;

        int reset = 0, held = -prices[0], sold = -1e9;

        for(int i = 1;i<n;i++){
            int prevSold = sold;
            sold = held + prices[i];
            held = max(held, reset - prices[i]);
            reset = max(reset, prevSold);
        }

        return max(sold, reset);




        
    }
};