class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int m = pref.length();

        int ans = 0;

        for(string& s: words){
            if(s.length()<m){
                continue;
            }

            int i;

            for(i = 0;i<m;i++){
                if(s[i]!=pref[i]){
                    break;
                }
            }

            if(i==m){
                ans++;
            }
        }

        return ans;
        
    }
};