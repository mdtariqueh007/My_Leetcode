class Solution {
public:
    int findComplement(int num) {

        string s = "";

        while(num>0){
            if(num%2){
                s += "1";
            }
            else{
                s += "0";
            }
            num = num/2;
        }

        for(int i = 0;i<s.size();i++){
            if(s[i]=='1'){
                s[i] = '0';
            }
            else{
                s[i] = '1';
            }
        }

        int sum = 0;
        long long pow2 = 1;


        for(int i = 0;i<s.length();i++){
            sum += (s[i] - '0') * pow2;
            pow2 = pow2 * 2;
        }

        return sum;

        
        
    }
};