class Solution {
    private:
    int dp[2010];
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int f(int ind,string&s){
        if(ind==s.length()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int minCost = INT_MAX;
        for(int end = ind;end<s.length();end++){
            if(isPalindrome(s,ind,end)){
                int cost = 1 + f(end+1,s);
                minCost = min(minCost,cost);
            }
        }
        return dp[ind] = minCost;
    }
public:
    int minCut(string s) {

        memset(dp,-1,sizeof(dp));

        return f(0,s)-1;
        
    }
};