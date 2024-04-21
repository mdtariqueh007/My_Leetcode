class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<bool> count(256,0);
        for(char c : word){
            count[c] = true;
        }

        int cnt = 0;

        for(char c : word){
            if(c>='a' && c<='z'){
                if(count[c-32]){
                    cnt++;
                    count[c-32] = false;
                    count[c] = false;
                }
            }else if(c>='A' && c<='Z'){
                if(count[c+32]){
                    cnt++;
                    count[c+32] = false;
                    count[c] = false;
                }
            }
        }

        return cnt;
        
    }
};