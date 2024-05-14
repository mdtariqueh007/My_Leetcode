class Solution {
    private:
    vector<int> helper(string s){
        int n = s.length();

        vector<int> lps(n,0);

        for(int i = 1;i<s.length()-1;i++){
            while((i+1+lps[i])<n && (i-1-lps[i])>=0 && s[i+1+lps[i]]==s[i-1-lps[i]]){
                lps[i]++;
            }
        }

        return lps;
    }
public:
    string longestPalindrome(string s) {

        string st = "$";

        for(int i = 0;i<s.length();i++){
            st += "#";
            st += s[i];
            
        }
        st += "#";
        st += "$";
        
        vector<int> lps = helper(st);

        int maxlen = 0;
        int ind = 0;
        for(int i = 0;i<lps.size();i++){
            if(lps[i]>maxlen){
                maxlen = lps[i];
                ind = i;
            }
        }

        int startInd = ind - maxlen + 1;
        int actInd = (startInd - 2)/2;

        return s.substr(actInd,maxlen);


    }
};