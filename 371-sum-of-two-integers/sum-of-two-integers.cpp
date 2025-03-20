class Solution {
public:
    int getSum(int a, int b) {

        int ans = a^b;

        int carry = a&b;

        while(carry!=0){
            carry = carry<<1;
            int temp = ans;
            ans = ans^carry;
            carry = temp&carry;
        }

        return ans;
 
    }
};