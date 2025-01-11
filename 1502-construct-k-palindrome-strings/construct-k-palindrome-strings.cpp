class Solution {
public:
    bool canConstruct(string s, int k) {

        int n = s.length();

        if(n<k){
            return false;
        }

        if(n==k){
            return true;
        }

        int oddCnt = 0;

        for(char c: s){
            int ind = c - 'a';

            oddCnt ^= (1<<(ind));
        }

        int setBits = __builtin_popcount(oddCnt);

        return setBits<=k;
        
    }
};