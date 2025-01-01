class Solution {
public:
    int maxScore(string s) {

        int n = s.length();

        int ones = 0;
        int zeros = 0;

        int maxi = -1e9;
        
        for(int i = 0;i<n-1;i++){
            if(s[i]=='1'){
                ones++;
            }
            else{
                zeros++;
            }

            maxi = max(maxi, zeros - ones);
        }

        if(s.back()=='1'){
            ones++;
        }

        return ones + maxi;
        
    }
};