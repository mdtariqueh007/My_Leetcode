class Solution {
    private:
    int parse_and(vector<int> &res){
        int ans = res[0];

        for(int i = 1;i<res.size();i++){
            ans = ans&res[i];
        }

        return ans;
    } 
    int parse_or(vector<int> &res){
        int ans = res[0];

        for(int i = 1;i<res.size();i++){
            ans = ans|res[i];
        }

        return ans;
    } 
    int parse_not(vector<int> &res){
        int ans = res[0];

        ans = 1 - ans;
        return ans;
    } 

public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression){
            if(c==',') continue;
            if(c==')'){

                vector<int> res;

                while(st.top()!='&' && st.top()!='|' && st.top()!='!'){
                    if(st.top()=='f'){
                        res.push_back(0);
                    }
                    else if(st.top()=='t'){
                        res.push_back(1);
                    }

                    st.pop();
                }

                if(st.top()=='&'){
                    st.pop();
                    if(parse_and(res)){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
                else if(st.top()=='|'){
                    st.pop();
                    if(parse_or(res)){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
                else if(st.top()=='!'){
                    st.pop();
                    if(parse_not(res)){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }

            }
            else{
                st.push(c);
            }
        }

        return st.top()=='t';
    }
};