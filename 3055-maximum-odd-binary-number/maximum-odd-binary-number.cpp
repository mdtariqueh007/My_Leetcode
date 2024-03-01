class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int cnt0 = 0,cnt1 = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
        
        string ans = "";
        
        for(int i = 0;i<cnt1-1;i++){
            ans += '1';
        }
        for(int i = 0;i<cnt0;i++){
            ans += '0';
        }
        
        ans += '1';
        
        return ans;
        
    }
};