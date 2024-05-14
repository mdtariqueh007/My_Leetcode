class Solution {
    private:
    vector<int> zScore(string&s){
        int n = s.length();

        vector<int> z(n,0);

        int l = 0;
        int r = 0;


        for(int i = 1;i<n;i++){
            if(i<=r){
                z[i] = min(r-i+1,z[i-l]);
            }

            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }

            if(i+z[i]-1>r){
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;

    }
    int dp[4001];
    int solve(string&inp,int ind){
        if(ind>=inp.length()){
            return 0;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        string s = inp.substr(ind);
        vector<int> z = zScore(s);

        int ans = 1;

        for(int i = 1;i<s.length();i++){
            if(z[i]>=i){
                ans = max(ans,1 + solve(inp,ind+i));
            }
        }

        return dp[ind] = ans;
    }
public:
    int deleteString(string s) {

        memset(dp,-1,sizeof(dp));

        return solve(s,0);
        
    }
};