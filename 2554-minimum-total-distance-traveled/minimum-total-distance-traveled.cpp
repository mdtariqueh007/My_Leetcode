class Solution {
    private:

    long long dp[101][101*101];
    long long solve(int robotInd,int factInd,vector<int>&robot,vector<int>&fact){
        if(robotInd==robot.size()){
            return 0;
        }
        if(factInd==fact.size()){
            return 1e12;
        }

        if(dp[robotInd][factInd]!=-1){
            return dp[robotInd][factInd];
        }

        long long take = abs(robot[robotInd] - fact[factInd]) + solve(robotInd+1,factInd+1,robot,fact);
        long long skip = solve(robotInd,factInd+1,robot,fact);

        return dp[robotInd][factInd] = min(take,skip);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        memset(dp,-1,sizeof(dp));

        vector<int> fact;
        for(int i = 0;i<factory.size();i++){
            for(int j = 0;j<factory[i][1];j++){
                fact.push_back(factory[i][0]);
            }
        }

        return solve(0,0,robot,fact);

    }
};