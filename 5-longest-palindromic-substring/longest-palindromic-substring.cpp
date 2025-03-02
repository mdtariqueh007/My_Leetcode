class Solution {
    private:
    string expand(int i, int j, string s){
        int left = i;
        int right = j;

        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1, right - left - 1);
    }
public:
    string longestPalindrome(string s) {

        string ans = "";

        for(int i = 0;i<s.size();i++){
            string oddLenString = expand(i, i, s);

            if(oddLenString.size()>ans.size()){
                ans = oddLenString;
            }

            string evenLenString = expand(i, i + 1, s);

            if(evenLenString.size() > ans.size()){
                ans = evenLenString;
            }
        }

        return ans;
        
    }
};