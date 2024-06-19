class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==0) return 0;
        if(divisor==1) return dividend;
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }

        bool sign = true;

        if(dividend>0 && divisor<0) sign = false;
        if(dividend<0 && divisor>0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);

        int ans = 0;

        while(n>=d){
            int cnt = 0;
            while(n>=(d<<cnt<<1)){
                cnt++;
            }

            ans += (1<<cnt);
            n = n - (d<<cnt);
        }

        return sign?ans:-1*ans;
    }
};