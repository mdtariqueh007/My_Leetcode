class Solution {
public:
    int generateKey(int num1, int num2, int num3) {

        int ans = 0;

        int pow10 = 1;

        while(num1>0 && num2>0 && num3>0){
            int d1 = num1%10;
            int d2 = num2%10;
            int d3 = num3%10;

            num1 /= 10;
            num2 /= 10;
            num3 /= 10;

            ans = min({d1,d2,d3})*pow10 + ans;
            pow10 *= 10;
        }

        return ans;
        
    }
};