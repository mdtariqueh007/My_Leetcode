class Solution {
    private:
    int dp[501][501];
    int solve(int word1Index, int word2Index, string &word1, string &word2){
        if(word1Index==word1.size()){
            return word2.size() - word2Index; //insert
        }

        if(word2Index==word2.size()){
            return word1.size() - word1Index; //delete
        }

        if(dp[word1Index][word2Index]!=-1){
            return dp[word1Index][word2Index];
        }

        if(word1[word1Index]==word2[word2Index]){
            return dp[word1Index][word2Index] = solve(word1Index+1, word2Index+1, word1, word2);
        }
        else{
            int insertOp = 1 + solve(word1Index, word2Index+1, word1, word2);
            int deleteOp = 1 + solve(word1Index+1, word2Index, word1, word2);
            int replaceOp = 1 + solve(word1Index+1, word2Index+1, word1, word2);

            return dp[word1Index][word2Index] = min(insertOp, min(deleteOp, replaceOp));
        }
    }
public:
    int minDistance(string word1, string word2) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, word1, word2);
        
    }
};