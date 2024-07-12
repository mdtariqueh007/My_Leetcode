class Solution {
    private:
    

    int dp[2001][3], check[2001][2001];
    bool isPalindrome(int i,int j,string&s){
        if(check[i][j]!=-1){
            return check[i][j];
        }

        int l = i, r = j;
        while(i<=j){
            if(s[i]!=s[j]){
                return check[l][r] = false;
            }
            i++;
            j--;
        }

        return check[l][r] = true;
    }
    bool solve(int ind,string &s,int partitions){
        if(ind>=s.length()){
            return partitions==0;
        }

        

        if(partitions==0){
            return isPalindrome(ind,s.size()-1,s);
        }

        if(dp[ind][partitions]!=-1){
            return dp[ind][partitions];
        }

        bool flag = false;


        for(int i = ind;i<s.size()-1;i++){
            if(isPalindrome(ind,i,s)){
                flag = flag || solve(i+1,s,partitions-1); 
            }
        }

        return dp[ind][partitions] = flag;


    }
public:
    bool checkPartitioning(string s) {
        memset(check,-1,sizeof(check));
        memset(dp,-1,sizeof(dp));
        return solve(0,s,2);
    }
};