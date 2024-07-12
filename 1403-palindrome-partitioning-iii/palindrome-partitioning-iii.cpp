class Solution {
    private:
    int n;
    int dp[101][101];
    int palindromeCost(int l,int r,string&s){
        int cost = 0; 
        while(l < r){
        // {   cout<<s[l]<<" "<<s[r]<<"\n";
            if(s[l++] != s[r--])
            {
                // cout<<"i\n";
                cost++;
            }
        }

        // cout<<"ccccc"<<cost<<"\n";

        return cost;
    }

    int solve(int ind, string &s,int par){
        if(ind>=n){
            // if(par>=0){
            //     return 1e9;
            // }

            return 0;
        }

        if(par == 0){
            return palindromeCost(ind,n-1,s);
        }

        if(dp[ind][par]!=-1){
            return dp[ind][par];
        }

        int mini = 1e9;

        for(int i = ind;i<(n-1);i++){
            int cost = palindromeCost(ind,i,s) + solve(i + 1,s,par - 1);
            // cout<<cost<<"\n";
            mini = min(mini,cost);
        }

        return dp[ind][par] = mini;
    }
public:
    int palindromePartition(string s, int k) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        // cout<<palindromeCost(3,6,s)<<"-----------\n";
        return  solve(0,s,k-1);
        // return -1;
    }
};