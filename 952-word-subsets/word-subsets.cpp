class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string> ans;

        vector<int> cntB(26,0);

        

        for(string& b: words2){

            vector<int> cnt(26,0);
            

            for(char c: b){
                cnt[c-'a']++;
            }

            for(int i = 0;i<26;i++){
                cntB[i] = max(cntB[i], cnt[i]);
            }
        }

        
        

        for(string& a: words1){
            vector<int> cntA(26,0);

            for(char c: a){
                cntA[c-'a']++;
            }

            bool flag = true;

            for(int i = 0;i<26;i++){
                if(cntA[i]<cntB[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(a);
            }


        }

        return ans;
        
    }
};