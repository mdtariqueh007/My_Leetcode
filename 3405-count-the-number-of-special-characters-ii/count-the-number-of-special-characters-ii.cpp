class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> count(256,-1);

        for(int i = 0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                count[word[i]] = i;
            }else if(word[i]>='A' && word[i]<='Z'){
                if(count[word[i]]==-1){
                    count[word[i]] = i;
                }
            }
        }

        int cnt = 0;

        for(int i = 'a';i<='z';i++){
            if(count[i]!=-1 && count[i]<count[i-32]){
                cnt++;
                // cout<<char(i)<<"\n";
            }
        }

        return cnt;

        
        
    }
};