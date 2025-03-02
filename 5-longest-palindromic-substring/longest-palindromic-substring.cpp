class Solution {
    private:
    bool isPal(int i, int j, string&s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
public:
    string longestPalindrome(string s) {

        for(int len = s.size();len>0;len--){
            for(int start = 0;start<=s.size()-len;start++){
                if(isPal(start, start+len-1, s)){
                    return s.substr(start, len);
                }
            }
        }

        return "";
        
    }
};