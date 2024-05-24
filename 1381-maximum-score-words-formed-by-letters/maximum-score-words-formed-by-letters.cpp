class Solution {
    private:
    void helper(vector<string>&words,int ind,vector<int>&count,vector<int>&req,vector<int>&score,int temp,int&ans){
        for(int i = 0;i<26;i++){
            if(count[i]<req[i]){
                return;
            }
        }
        ans = max(ans,temp);
        if(ind==words.size()){
            return;
        }


        for(int i = ind;i<words.size();i++){
            for(char c : words[i]){
                req[c-'a']++;
                temp += score[c-'a'];
            }
            helper(words,i+1,count,req,score,temp,ans);
            for(char c : words[i]){
                req[c-'a']--;
                temp -= score[c-'a'];
            }
        }
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26,0);

        for(char c : letters){
            count[c-'a']++;
        }

        vector<int> req(26,0);


        int ans = 0, temp = 0;

        helper(words,0,count,req,score,temp,ans);

        return ans;

    }
};