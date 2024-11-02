class Solution {
public:
    bool isCircularSentence(string sentence) {

        char last = sentence.back();

        stringstream ss(sentence);
        string word;

        while(ss>>word){
            if(word[0]!=last){
                return false;
            }
            last = word.back();
        }

        return true;


    }
};