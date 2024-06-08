class Solution {
    private:

    int dp[23][401][2][2];
    const int mod = 1e9+7;
    long long solve(int ind,int sum,int tight1,int tight2,string&nums1,string&nums2){
        if(sum<0){
            return 0;
        }

        if(ind==nums2.size()){
            return 1;
        }

        if(dp[ind][sum][tight1][tight2]!=-1){
            return dp[ind][sum][tight1][tight2]%mod;
        }

        int lb = tight1?nums1[ind] - '0':0;

        int ub = tight2?nums2[ind] - '0':9;

        long long ans = 0;

        for(int dig = lb;dig<=ub;dig++){

            if(dig<=sum){
                ans = (ans%mod + solve(ind+1,sum-dig,(tight1 && dig==lb),(tight2 && dig==ub),nums1,nums2)%mod)%mod;    
            }

        }

        return dp[ind][sum][tight1][tight2] = ans%mod;
    }
    // long long helper(string l,string r,int sum){
    //     memset(dp,-1,sizeof(dp));
    //     long long high = solve(0,sum,1,r);
    //     memset(dp,-1,sizeof(dp));
    //     string L_1 = to_string(strol(l)-1);
    //     long long low = solve(0,sum,1,L_1);

    //     return (high - low + mod)%mod;
    // }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {

        memset(dp,-1,sizeof(dp));

        int extraZeros = num2.size() - num1.size();

        num1 = string(extraZeros,'0')+num1;
        
        long long total = solve(0,max_sum,1,1,num1,num2);
        long long remove = solve(0,min_sum-1,1,1,num1,num2);

        return (total - remove + mod)%mod;

        

        
    }
};