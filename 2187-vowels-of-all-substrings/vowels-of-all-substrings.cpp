class Solution {
    private:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    long long countVowels(string word) {

        long long ans = 0;

        int n = word.length();

        for(int i = 0;i<n;i++){
            if(isVowel(word[i])){
                long long leftChoices = (i+1);
                long long rightChoices = (n-i);

                ans += (leftChoices * rightChoices);
            }
        }

        return ans;
        
    }
};