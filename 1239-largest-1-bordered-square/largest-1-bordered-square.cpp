class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(n,{0,0}));

        if(grid[0][0]==1){
            dp[0][0] = {1,1};
        }

        for(int j = 1;j<n;j++){
            if(grid[0][j]==1){
                dp[0][j] = {dp[0][j-1].first+1,1};
            }
        }

        for(int i = 1;i<m;i++){
            if(grid[i][0]==1){
                dp[i][0] = {1,dp[i-1][0].second+1};
            }
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(grid[i][j]==1)
                    dp[i][j] = {dp[i][j-1].first+1, dp[i-1][j].second+1};
            }
        }

        int res = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int val = min(dp[i][j].first, dp[i][j].second);

                while(val>res){
                    if(dp[i][j-val+1].second>=val && dp[i-val+1][j].first>=val){
                        res = val;
                    }
                    val--;
                }

            }
        }

        return res*res;

    }
};