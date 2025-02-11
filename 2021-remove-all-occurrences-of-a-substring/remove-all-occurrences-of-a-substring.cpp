class Solution {
public:
    string removeOccurrences(string s, string part) {

        string ans = s;

        while(ans.find(part)!=string::npos){
            int i = ans.find(part);
            ans = ans.substr(0,i) + ans.substr(i+part.length());
        }

        return ans;
        
    }
};