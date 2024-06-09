class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {

        vector<int> ans;

        long long prevRemainder = 0;

        for(int i = 0 ;i<word.size();i++){
            int dig = word[i] - '0';

            long long newDividend = prevRemainder*10 + dig;

            long long rem = newDividend%m;

            if(rem==0){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }

        
            prevRemainder = rem;
        }

        return ans;
        
    }
};