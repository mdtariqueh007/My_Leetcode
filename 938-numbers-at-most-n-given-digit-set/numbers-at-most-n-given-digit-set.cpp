class Solution {

    int dp[10][2][2];

    int solve(int ind,int tight,bool isLeading,string&num,unordered_set<int>&st){
        if(ind==num.size()){
            return 1;
        }

        if(dp[ind][tight][isLeading]!=-1){
            return dp[ind][tight][isLeading];
        }

        int ans = 0;

        int ub = tight?(num[ind]-'0'):9;

        if(isLeading){
            ans += solve(ind+1,0,1,num,st);
        }

        for(int dig = 0;dig<=ub;dig++){
            if(st.find(dig)!=st.end()){
                ans += solve(ind+1,(tight && dig==ub),0,num,st);
            }
        }

        return dp[ind][tight][isLeading] = ans;
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        string num = to_string(n);

        unordered_set<int> st;

        for(string s: digits){
            st.insert(s[0]-'0');
        }

        memset(dp,-1,sizeof(dp));

        return solve(0,1,1,num,st) - 1;
    }
};