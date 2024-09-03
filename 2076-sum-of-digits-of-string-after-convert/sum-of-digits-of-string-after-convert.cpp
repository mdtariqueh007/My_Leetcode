class Solution {
    private:

    int sumOfDigits(int num){
        int sum = 0;


        while(num>0){
            sum += num%10;

            num = num/10;
        }

        return sum;
    }

public:
    int getLucky(string s, int k) {

        int sum = 0;

        for(char ch  : s){
            int val = ch - 'a' + 1;

            sum += val/10 + val%10;
        }

        k -= 1;

        while(k-->0 && sum>=10){
            sum = sumOfDigits(sum);
        }

        return sum;

        
        
    }
};