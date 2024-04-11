class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        if(n==k) return "0";
        stack<char> st;
        for(char digit : num){
            while(!st.empty() && digit<st.top() && k>0){
                st.pop();
                k--;
            }
            if(st.empty() && digit=='0') continue;
            st.push(digit);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};