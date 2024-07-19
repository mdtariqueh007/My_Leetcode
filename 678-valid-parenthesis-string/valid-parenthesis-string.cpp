class Solution {
    private:
    int dp[101][101];
    bool solve(int ind,string&s,int cnt){
        if(cnt<0){
            return false;
        }

        if(ind==s.length()){
            return cnt==0;
        }

        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }

        bool ans = false;

        if(s[ind]=='('){
            ans = solve(ind+1,s,cnt+1);
        }
        else if(s[ind]==')'){
            ans = solve(ind+1,s,cnt-1);
        }
        else{
            ans = solve(ind+1,s,cnt+1);
            if(!ans){
                ans = solve(ind+1,s,cnt-1);
            }
            if(!ans){
                ans = solve(ind+1,s,cnt);
            }
        }

        return dp[ind][cnt] = ans;
        
    }
public:
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        
        return solve(0,s,0);
    }
};