class Solution {
    private:
    int getScore(int alice,int bob){
        if(alice==bob){
            return 0;
        }
        else if((alice=='F' && bob=='E') || (alice=='W' && bob=='F') || (alice=='E' && bob=='W')){
            return -1;
        }

        return 1;
    }
    string ch = "FWE";
    int dp[1001][2001][4];
    const int mod = 1e9 + 7;
    long long solve(string&s, int ind,int score, int prev){
        if(ind==s.length()){
            if(score>=1){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[ind][score+1000][prev]!=-1){
            return dp[ind][score+1000][prev]%mod;
        }

        long long ways = 0;

        for(int i = 0;i<3;i++){
            if(prev==i){
                continue;
            }


            ways = (ways%mod + solve(s,ind+1,score + getScore(s[ind],ch[i]),i)%mod)%mod;


        }

        return dp[ind][score+1000][prev] = ways%mod;
    }
public:
    int countWinningSequences(string s) {

        memset(dp,-1,sizeof(dp));

        return solve(s,0,0,3);
        
    }
};