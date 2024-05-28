class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);

        string temp;

        
        string ans = "";        

        while(ss>>temp){
            temp += " ";
            ans = temp + ans;
            
        }

        return ans.substr(0,ans.size()-1);        
    }
};