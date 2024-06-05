class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26,0);
        vector<int> count2(26,0);

        for(char c : words[0]){
            count[c-'a']++;
        }

        for(int i = 1;i<words.size();i++){
            
            for(char c : words[i]){
               
                    count2[c-'a']++;
                
                
            }

            for(int i = 0;i<26;i++){
                count[i] = min(count[i],count2[i]);
                count2[i] = 0;
            }
        }

        vector<string> ans;

        for(int i = 0;i<26;i++){

                int cnt = count[i];

                string s(1,i+'a');
                while(cnt--){
                    ans.push_back(s);
                } 
            
        }

        return ans;
    }
};