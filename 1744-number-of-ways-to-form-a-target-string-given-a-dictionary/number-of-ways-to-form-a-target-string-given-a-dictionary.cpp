class Solution {
    private:
    const int mod = 1e9 + 7;
    long long dp[1001][1001];
    int freq[1001][26];
    long long solve(int i, int j, string& target, vector<string>&words){
        if(i==target.size()){
            return 1;
        }
        if(j==words[0].size() || words[0].size() - j<target.size() - i){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        long long cnt = 0;

        // for(int ind = 0;ind<words.size();ind++){
        //     if(words[ind][j]==target[i]){
        //         cnt += solve(i+1,j+1,target, words)%mod;
        //     }
        // }

        int currChar = target[i] - 'a';

        cnt += (freq[j][currChar] * solve(i+1,j+1, target, words))%mod;

        cnt += solve(i, j+1, target, words)%mod;

        return dp[i][j] = cnt%mod;
    }
public:
    int numWays(vector<string>& words, string target) {

        memset(dp,-1,sizeof(dp));
        memset(freq,0,sizeof(freq));

        for(int i = 0;i<words.size();i++){
            for(int j = 0;j<words[0].size();j++){
                int currChar = words[i][j] - 'a';
                freq[j][currChar]++;
            }
        }

        return solve(0,0,target, words);
        
    }
};