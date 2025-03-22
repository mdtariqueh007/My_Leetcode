class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(),[&](string s1, string s2){
            return s1.size()<s2.size();
        });

        unordered_map<string, int> dp;

        int ans = 0;

        for(string word: words){
            int maxLen = 1;

            for(int i = 0;i<word.size();i++){
                string newWord = word.substr(0,i) + word.substr(i+1);
                maxLen = max(maxLen, dp[newWord] + 1);
            }

            dp[word] = maxLen;
            ans = max(ans, maxLen);
        }

        return ans;
        
    }
};