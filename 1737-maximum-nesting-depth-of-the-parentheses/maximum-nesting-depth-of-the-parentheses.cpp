class Solution {
public:
    int maxDepth(string s) {

        int open = 0, close = 0;

        int res = 0;
        
        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            // else{
                res = max(res,open-close);
            // }
        }

        return res;
        
    }
};