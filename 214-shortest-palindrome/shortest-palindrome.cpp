class Solution {
    private:
    int LPS(string &s){
        int n = s.length();

        vector<int> lps(n,0);

        int len = 0;
        int i = 1;

        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n-1];
    }
public:
    string shortestPalindrome(string s) {
        string rev(s);

        reverse(rev.begin(),rev.end());

        string str = s + "#" + rev;

        int maxPal = LPS(str);

        int charsToAdd = s.length() - maxPal;

        string temp = rev.substr(0,charsToAdd);

        return temp+s;
    }
};