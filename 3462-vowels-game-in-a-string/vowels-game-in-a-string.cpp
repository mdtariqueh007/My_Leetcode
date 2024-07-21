class Solution {
public:
    bool doesAliceWin(string s) {

        int cntVowels = 0;


        for(char c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                cntVowels++;
            }
        }

        if(cntVowels==0){
            return false;
        }

        return true;
        
    }
};