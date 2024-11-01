class Solution {
    private:
    long long dp[4][100000];
    long long solve(int i,int j,vector<int>&a,vector<int>&b){
        if(i==4){
            return 0;
        }

        if(j==b.size()){
            return -1e12;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        long long take = (long long)a[i]*(long long)b[j] + solve(i+1,j+1,a,b);
        long long notTake = solve(i,j+1,a,b);

        return dp[i][j] = max(take,notTake);
    }
public:
    long long maxScore(vector<int>& a, vector<int>& b) {

        memset(dp,-1,sizeof(dp));
        return solve(0,0,a,b);
    }
};