class Solution {
public:
    string reverseParentheses(string s) {

        stack<int> st;

        string temp = "";

        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                st.push(temp.length());
            }
            else if(s[i]==')'){
                int ind = st.top();
                st.pop();
                reverse(temp.begin() + ind,temp.end());
            }
            else{
                temp += s[i];
            }
        }

        return temp;
        
    }
};