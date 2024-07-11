class Solution {
    private:
    int dp[102][102];
    int solve(int l,int r,vector<int>&cuts){
        if(r-l<2){
            return 0;
        }

        if(dp[l][r]!=-1){
            return dp[l][r];
        }

        int mini = 1e9;

        for(int ind = l + 1;ind<=r - 1;ind++){
            int ans = (cuts[r] - cuts[l]) + solve(l,ind,cuts) + solve(ind,r,cuts);

            mini = min(mini, ans);
        }

        return dp[l][r] =  mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());

        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        memset(dp,-1,sizeof(dp));

        return solve(0,cuts.size()-1,cuts);
    }
};