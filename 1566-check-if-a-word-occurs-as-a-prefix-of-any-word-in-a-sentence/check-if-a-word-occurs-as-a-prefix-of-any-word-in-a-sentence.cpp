class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        stringstream ss(sentence);

        string temp;

        vector<string> vec;

        while(ss>>temp){
            vec.push_back(temp);
        }

        int i = 0;

        for(string s: vec){
            if(s.find(searchWord)==0){
                return i + 1;
            }
            i++;
        }

        return -1;
        
    }
};