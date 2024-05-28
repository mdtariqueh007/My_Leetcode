class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);

        string temp;

        
        s = "";        

        while(ss>>temp){
            temp += " ";
            s = temp + s;
            
        }

        return s.substr(0,s.size()-1);        
    }
};