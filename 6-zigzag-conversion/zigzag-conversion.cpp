class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows<=1){
            return s;
        }

        vector<string> table(numRows,"");

        int currentLine = 0;
        bool reachedEnd = true;

        for(int i = 0;i<s.size();i++){
            if(currentLine==0 || currentLine==numRows -1){
                reachedEnd = !reachedEnd;
            }

            table[currentLine] += s[i];

            if(!reachedEnd){
                currentLine++;
            }else{
                currentLine--;
            }
        }

        string ans;

        for(int i = 0;i<numRows;i++){
            ans += table[i];
        }

        return ans;
        
    }
};