class Solution {
public:
    char kthCharacter(int k) {

        string s = "a";

        while(s.size()<k){
            string to_append = "";

            for(char c : s){
                to_append += (c - 'a' + 1)%26 + 'a';
            }

            s += to_append;
        }

        return s[k-1];
        
    }
};