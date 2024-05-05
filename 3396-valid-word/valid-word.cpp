class Solution {
public:
    bool isValid(string word) {

        if(word.length()<3){
            return false;
        }
        
        set<char> vowels({'a','e','i','o','u','a'-32,'e'-32,'i'-32,'o'-32,'u'-32});

        bool isVowel = false;
        bool isCons = false;

        bool ans = false;

        for(char c : word){
            if(!(c>='a' && c<='z') && !(c>='A' && c<='Z') && !(c>='0' && c<='9')){
                return false;
            }
            if(vowels.find(c)!=vowels.end()){
                isVowel = true;
            }else{
                if((c>='a' && c<='z') || (c>='A' && c<='Z'))
                isCons = true;
            }

            if(isVowel && isCons){
                ans = true;
            }
        }

        if(ans){
            return ans;
        }

        return false;

    }
};