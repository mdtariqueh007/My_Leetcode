class Solution {
    private:
    int helper(int ind,unordered_set<string>&st,string&s,vector<int>&dp){
        if(ind>=s.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        string currString = "";
        int ans = s.size();
        for(int currInd = ind;currInd<s.size();currInd++){
            currString.push_back(s[currInd]);
            int extras = 0;
            if(st.count(currString)==0){
                extras = currString.size();
            }
            extras += helper(currInd+1,st,s,dp);
            ans = min(ans,extras);
        }

        return dp[ind] = ans;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {

        unordered_set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(s.size(),-1);

        return helper(0,st,s,dp);
        
    }
};