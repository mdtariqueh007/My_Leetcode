class Solution {
    private:
    long long dp[(int)1e5+1];
    int getNextPassenger(vector<vector<int>>&rides,int val){
        int low = 0;
        int high = rides.size() - 1;

        int ans = rides.size();

        while(low<=high){
            int mid = low + (high - low)/2;

            if(rides[mid][0]>=val){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
    long long solve(int ind,vector<vector<int>>&rides){
        if(ind>=rides.size()){
            return 0;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        int i = getNextPassenger(rides,rides[ind][1]);

        long long pick = (rides[ind][1] - rides[ind][0] + rides[ind][2]) + solve(i,rides);
        long long notPick = solve(ind+1,rides);

        return dp[ind] = max(pick,notPick);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(),rides.end());

        memset(dp,-1,sizeof(dp));

        return solve(0,rides);

        
        
    }
};