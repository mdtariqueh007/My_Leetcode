class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        
        
        int j = 0;
        int n = s.length();
        int m = t.length();
        
        int cnt = 0;
        
        for(int i = 0;i<n&&j<m;i++){
            if((s[i]==t[j]) || (s[i]+1 == t[j]) || (s[i]=='z' && t[j]=='a')){
                
                
                    j++;
            }
               
        }
               
    return j==m;
        
    }
};