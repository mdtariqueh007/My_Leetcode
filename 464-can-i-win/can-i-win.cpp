class Solution {

    private:

    int dp[1<<21];

    bool solve(int n,int s,int mask){
        if(s<=0){
            return false;
        }

        if(dp[mask]!=-1){
            return dp[mask];
        }

        for(int i = 1;i<=n;i++){
            if(mask & (1<<i)){
                continue;
            }
            if(solve(n,s-i,mask|(1<<i))==false){
                return dp[mask] = true;
            }
        }

        return dp[mask] = false;


    }
    
public:
    bool canIWin(int n, int s) {

        if(s<=n){
            return true;
        }

        if((n*(n+1))/2<s){
            return false;
        }

        // vector<int> st(n+1,0);

        memset(dp,-1,sizeof(dp));

        return solve(n,s,0);


        
    }
};