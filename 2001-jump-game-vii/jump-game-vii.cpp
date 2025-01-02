class Solution {
    private:
    // int dp[100001];
    // bool allZeros(string s){
    //     sort(s.begin(), s.end());

    //     return s[0]==s.back();
    // }
    // int solve(int ind,string s,int minJump,int maxJump){
    //     if(ind==s.length() - 1){
    //         return s[ind]=='0';
    //     }

    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }

    //     int ans = 0;

    //     for(int i = ind+1;i<s.length();i++){
    //         if(i>=(ind+minJump) && i<=(ind+maxJump) && s[i]=='0'){
    //             ans = solve(i, s, minJump, maxJump);

    //             if(ans){
    //                 break;
    //             }
    //         }
    //     }

    //     return dp[ind] = ans;
    // }

public:
    bool canReach(string s, int minJump, int maxJump) {

        // if(s.back()!='0'){
        //     return false;
        // }

        // if(allZeros(s)){
        //     return true;
        // }

        // // if(maxJump>=s.length() && s.back()=='0'){
        // //     return true;
        // // }

        // memset(dp,-1,sizeof(dp));
        // return solve(0,s,minJump,maxJump);

        // int n = s.length();

        // vector<bool> dp(n, false);

        // dp[n-1] = s[n-1]=='0';

        // for(int i = n - 2;i>=0;i--){
        //     bool ans = false;

        //     for(int j = i + 1;j<n;j++){
        //         if(j>=(i+minJump) && j<=(i+maxJump) && s[j]=='0'){
        //             ans = dp[j];
        //         }
        //     }

        //     dp[i] = ans;
        // }


        // return dp[0];

        // if(s.back()!='0'){
        //     return false;
        // }

        // int n = s.length();

        // queue<int> q;
        // vector<bool> vis(n, false);

        // q.push(0);

        // vis[0] = true;

        // while(!q.empty()){
        //     int i = q.front();
        //     q.pop();

        //     if(i==n-1){
        //         return true;
        //     }

        //     for(int j = i + minJump;j<=i+maxJump && j<n-1;j++){
        //         if(!vis[j] && s[j]=='0'){
        //             vis[j] = true;

        //             q.push(j);
        //         }


        //     }
        // }

        // return false;

        if(s.back()!='0'){
            return false;
        }

        int n = s.length();

        queue<int> q;

        q.push(0);

        int maxReach = 0;

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(i==n-1){
                return true;
            }

            for(int j = max(i+minJump, maxReach);j<=min(i+maxJump,n-1);j++){
                if(s[j]=='0'){
                    q.push(j);
                }
            }

            maxReach = min(i + maxJump + 1, n - 1);
        }

        return false;
    }
};