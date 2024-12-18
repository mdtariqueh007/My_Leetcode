class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {


        vector<int> ans = prices;

        stack<int> st;

        for(int i = 0;i<prices.size();i++){
            while(!st.empty() && prices[i]<=prices[st.top()]){
                ans[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
        
        
    }
};