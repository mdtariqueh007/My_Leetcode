class Solution {
public:
    int minimumDeletions(string s) {

        int ans = 0;

        stack<char> st;

        for(int i = 0;i<s.length();i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='b'){
                    ans++;
                    st.pop();
                }
                
            }
            else{
                    st.push(s[i]);
                }
        }

        return ans;
        
    }
};