class Solution {
    private:
    int dp[366][366+31];
    int solve(int ind,vector<int>&days,int validTill,vector<int>&costs){
        if(validTill>=days.back()){
            return 0;
        }

        if(dp[ind][validTill]!=-1){
            return dp[ind][validTill];
        }

        int oneDay, sevenDay, thirtyDay;

        oneDay = sevenDay = thirtyDay = 1e9;



        if(validTill>=days[ind]){
            oneDay = sevenDay = thirtyDay = solve(ind+1,days,validTill,costs);
        }
        else{
            // if(validTill+1>=days[ind]){
                oneDay = costs[0] + solve(ind+1,days,days[ind]+1-1,costs);
            // }
            // if(validTill+7>=days[ind]){
                sevenDay = costs[1]  + solve(ind+1,days,days[ind]+7-1,costs);
            // }
            // if(validTill+30>=days[ind]){
                thirtyDay = costs[2] + solve(ind+1,days,days[ind]+30-1,costs);
            // }
        }

        return dp[ind][validTill] = min({oneDay,sevenDay,thirtyDay});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        memset(dp,-1,sizeof(dp));

        return solve(0,days,0,costs);

        
    }
};