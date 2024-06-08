class Solution {
    private:

    int dp[10][10][2];
    
    int solve(int ind,int cnt,int tight,string&num){
        if(ind==num.size()){
        
            return cnt;
        }

        if(dp[ind][cnt][tight]!=-1){
            return dp[ind][cnt][tight];
        }

        int ub = (tight)?(num[ind]-'0'):9;

        int ans = 0;

        for(int dig = 0;dig<=ub;dig++){
            
            ans += solve(ind+1,(dig==1)?cnt+1:cnt,(tight && dig==ub),num);
            
        }

        return dp[ind][cnt][tight] = ans;
    }
public:
    int countDigitOne(int n) {

        memset(dp,-1,sizeof(dp));

        string num = to_string(n);

        return solve(0,0,1,num);

        

        
        
    }
};