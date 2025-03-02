class Solution {
    private:
    int dp[301];
    bool solve(int ind, string&s, set<string>&st){
        if(ind==s.length()){
            return true;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        for(int end = ind;end<s.size();end++){
            if(st.find(s.substr(ind, end - ind + 1))!=st.end() && solve(end+1, s, st)){
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        set<string> st(wordDict.begin(), wordDict.end());

        memset(dp, -1, sizeof(dp));

        return solve(0,s, st);
        
    }
};