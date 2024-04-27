class Solution {
    private:
    int dp[101][101];
    int f(string& ring,string& key,int curr,int keyInd){
        if(keyInd==key.length()){
            return 0;
        }

        if(dp[curr][keyInd]!=-1){
            return dp[curr][keyInd];
        }

        int ans = 1e9;

        for(int i = 0;i<ring.length();i++){
            if(ring[i]==key[keyInd]){
                int stepsBetween = abs(i - curr);
                int stepsAround = abs((int)ring.length() - stepsBetween);
                int minSteps = min(stepsBetween, stepsAround);

                minSteps += f(ring,key,i,keyInd+1) + 1;

                ans = min(ans,minSteps);
            }
        }

        return dp[curr][keyInd] = ans;
    }
public:
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return f(ring,key,0,0);
    }
};