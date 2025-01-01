class Solution {
public:
    int maxScore(string s) {

        int n = s.length();

        int ones = 0;

        for(char c: s){
            if(c=='1'){
                ones++;
            }
        }

        int ans = 0;
        int zeros = 0;

        for(int i = 0;i<n-1;i++){
            if(s[i]=='1'){
                ones--;
            }
            else{
                zeros++;
            }

            ans = max(ans, zeros + ones);
        }

        return ans;
        
    }
};