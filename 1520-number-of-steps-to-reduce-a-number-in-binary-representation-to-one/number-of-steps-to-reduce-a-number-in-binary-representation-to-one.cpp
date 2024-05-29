class Solution {
public:
    int numSteps(string s) {

        int n = s.length();

        int res = 0;

        int carry = 0;

        for(int i = n-1;i>0;i--){
            if((carry==1 && s[i]=='0') || (carry==0 && s[i]=='1')){
                res += 2;
                carry = 1;
            }else if(s[i]=='0' && carry==0){
                res++;
            }else{
                res++;
                carry = 1;
            }
        }

        if(carry) res++;

        return res;
        
    }
};