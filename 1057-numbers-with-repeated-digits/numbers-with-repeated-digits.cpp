class Solution {
    private:
    int dp[10][2][2][1024];
    int solve(int ind,int tight,bool isRepeated,string& num,int mask){
        if(ind==num.size()){
            if(isRepeated && mask!=0){
                return 1;
            }

            return 0;
        }

        if(dp[ind][tight][isRepeated][mask]!=-1){
            return dp[ind][tight][isRepeated][mask];
        }

        int ans = 0;

        int ub = tight ? num[ind]-'0':9;

        for(int dig = 0;dig<=ub;dig++){
            
            ans += solve(ind+1,(tight && dig==ub),(mask==0 && dig==0)?0:isRepeated | bool(mask & 1<<dig), num ,(mask==0 && dig==0)?mask:(mask|(1<<dig)));
            
        }

        return dp[ind][tight][isRepeated][mask] = ans;
    }
public:
    int numDupDigitsAtMostN(int n) {

        

        // memset(mark,0,sizeof(mark));

        string num = to_string(n);

        memset(dp,-1,sizeof(dp));

        return solve(0,1,0,num,0);
        
    }
};