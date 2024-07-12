class Solution {
    

public:
    int maximumGain(string s, int x, int y) {
        

        stack<char> st;

        int res = 0;

        if(y>=x){

        for(char c : s){
            if(c=='a'){
                if(!st.empty()){
                    if(st.top()=='b'){
                        st.pop();
                        res += y;
                    }
                    else{
                        st.push(c);
                    }
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }

        s = "";

        while(!st.empty()){
            s += st.top();
            st.pop();
        }

        reverse(s.begin(),s.end());

        for(char c : s){
            if(c=='b'){
                if(!st.empty()){
                    if(st.top()=='a'){
                        st.pop();
                        res += x;
                    }
                    else{
                        st.push(c);
                    }
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }
        }
        else{
        for(char c : s){
            if(c=='b'){
                if(!st.empty()){
                    if(st.top()=='a'){
                        st.pop();
                        res += x;
                    }
                    else{
                        st.push(c);
                    }
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }

        s = "";


        while(!st.empty()){
            s += st.top();
            st.pop();
        }


        reverse(s.begin(),s.end());


            for(char c : s){
            if(c=='a'){
                if(!st.empty()){
                    if(st.top()=='b'){
                        st.pop();
                        res += y;
                    }
                    else{
                        st.push(c);
                    }
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }
        }

        return res;


        


    }
};