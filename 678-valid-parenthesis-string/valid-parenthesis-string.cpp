class Solution {
    private:
    int dp[101][101];
    bool f(int i,string&s,int bal){
        if(i>=s.size()){
            return bal==0;
        }

        if(bal<0) return false;

        if(dp[i][bal]!=-1) return dp[i][bal];

        bool ans = false;

        if(s[i]=='*'){
            ans = ans | f(i+1,s,bal+1);
            if(bal) ans = ans | f(i+1,s,bal-1);
            ans = ans | f(i+1,s,bal);
        }
        else{
            if(s[i]=='(') ans = ans | f(i+1,s,bal+1);
            else ans = ans | f(i+1,s,bal-1);
        }

        return dp[i][bal] = ans;
    }
public:
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s,0);
    }
};