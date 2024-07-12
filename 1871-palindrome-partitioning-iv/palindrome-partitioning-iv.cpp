class Solution {
    private:
    bool isPalindrome(int i,int j,string&s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int dp[2001][3];
    bool solve(int ind,string &s,int partitions){
        if(ind>=s.length()){
            return partitions==0;
        }

        if(dp[ind][partitions]!=-1){
            return dp[ind][partitions];
        }

        if(partitions==0){
            return isPalindrome(ind,s.size()-1,s);
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
        memset(dp,-1,sizeof(dp));
        return solve(0,s,2);
    }
};