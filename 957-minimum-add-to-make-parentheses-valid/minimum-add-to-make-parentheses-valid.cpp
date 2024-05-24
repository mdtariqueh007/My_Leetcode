class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;

        int res = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }else{
                    res++;
                }
            }
        }

        if(open){
            res += open;
        }

        return res;
    }
};