class Solution {
    private:
    int dp[100001];
    int f(int i,vector<int>&energy,int k){
        if(i>=energy.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int ans = energy[i] + f(i+k,energy,k);

        return dp[i] = ans;
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();

        memset(dp,-1,sizeof(dp));

        int ans = -1e9;

        for(int i = 0;i<n;i++){
            ans = max(ans,f(i,energy,k));
        }

        return ans;

        

        
    }
};