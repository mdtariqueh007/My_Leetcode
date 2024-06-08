class Solution {
    private:
    int dp[32][2][2];
    int solve(int ind,int prev,int tight,string &num){
        if(ind==num.size()){
            return 1;
        }

        if(dp[ind][prev][tight]!=-1){
            return dp[ind][prev][tight];
        }

        int ans = 0;

        int ub = tight?num[ind]-'0':1;

        for(int dig = 0;dig<=ub;dig++){
            if(prev==1 && dig==1) continue;

            ans += solve(ind+1,dig,(tight && dig==ub),num);
        }

        return dp[ind][prev][tight] =  ans;
    }
public:
    int findIntegers(int n) {

        string bits;
        

        while(n>0){
            bits.push_back((n&1)+'0');
            n = n>>1;
        }

        reverse(bits.begin(),bits.end());

        // for(char i : bits){
        //     cout<<i<<" ";
        // }

        // cout<<"\n";

        memset(dp,-1,sizeof(dp));

        return solve(0,0,1,bits);
        
    }
};