class Solution {
    private:
    void solve(vector<int>&strength, int cnt, int x, int k, int currAns, int& ans, vector<bool>&unlocked){

        if(currAns>=ans){
            return;
        }

        if(cnt==strength.size()){
            ans = min(ans, currAns);
            return;
        }

        for(int i = 0;i<strength.size();i++){
            if(unlocked[i]){
                continue;
            }

            int reqTime = (strength[i] +x - 1)/x;
            unlocked[i] = true;
            solve(strength, cnt+1,x+k,k,currAns+reqTime, ans,unlocked);
            unlocked[i] = false;
        }
    }
public:
    int findMinimumTime(vector<int>& strength, int k) {

        int n = strength.size();
        int ans = 1e9;

        vector<bool> unlocked(n, false);

        solve(strength, 0, 1,k,0,ans,unlocked);

        return ans;
        
    }
};