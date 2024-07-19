class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;

        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                mini = mini + 1;
                maxi = maxi + 1;
            }
            else if(s[i]==')'){
                mini = mini - 1;
                maxi = maxi - 1;
            }
            else{
                mini = mini - 1;
                maxi = maxi + 1;
            }

            mini = max(0,mini);

            if(maxi<0) return false;
        }

        return mini==0;
    }
};