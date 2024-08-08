class Solution {
    private:
    int dp[100001][2];
    int solve(string&s,int ind,int prev){
        if(ind>=s.length()){
            return 0;
        }

        if(dp[ind][prev]!=-1){
            return dp[ind][prev];
        }

        int flip = 1e9;
        int noFlip = 1e9;

        if(s[ind]=='0'){
            if(prev==1){
                flip = 1 + solve(s,ind+1,1);
            }
            else{
                flip = 1 + solve(s,ind+1,1);
                noFlip = solve(s,ind+1,0);
            }
        }
        else{
            if(prev==1){
                noFlip = solve(s,ind+1,1);
            }
            else{
                flip = 1 + solve(s,ind+1,0);
                noFlip = solve(s,ind+1,1);
            }
        }

        return dp[ind][prev] = min(flip,noFlip);
    }
public:
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};