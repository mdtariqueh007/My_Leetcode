class Solution {
    private:
    const int mod = 1e9 + 7;
    vector<vector<long long>> multiply(vector<vector<long long>>&A, vector<vector<long long>>&B){
        vector<vector<long long>> res(26, vector<long long>(26,0));

        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                for(int k = 0;k<26;k++){
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j])%mod;
                }
            }
        }

        return res;
    }

    vector<vector<long long>> matrixExponentiation(vector<vector<long long>>& base, int n){
        vector<vector<long long>> res(26, vector<long long>(26,0));

        for(int i = 0;i<26;i++){
            res[i][i] = 1;
        }

        while(n>0){
            if(n&1){
                res = multiply(res, base);
            }
           
            base = multiply(base, base);
            n = n>>1;
            
        }

        return res;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> cnt(26,0);

        for(char c: s){
            cnt[c-'a']++;
        }

        vector<vector<long long>> T(26, vector<long long>(26,0));

        for(int i = 0;i<26;i++){
            for(int j = 1;j<=nums[i];j++){
                T[i][(i+j)%26]++;
            }
        }   

        vector<vector<long long>> Tpow(26, vector<long long>(26,0));

        Tpow = matrixExponentiation(T, t);

        vector<long long> ans(26,0);

        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                ans[i] = (ans[i] + Tpow[i][j] * cnt[i])%mod;
            }
        }

        int res = 0;

        for(int i = 0;i<26;i++){
            res = (res + ans[i])%mod;
        }

        return res;
    }
};