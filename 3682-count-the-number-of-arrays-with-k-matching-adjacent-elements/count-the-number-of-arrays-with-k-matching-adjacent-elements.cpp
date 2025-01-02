class Solution {
    private:
    const int mod = 1e9 + 7;
    
    long long power(long long base, long long exp){
        
        long long res = 1;

        while(exp>0){
            if(exp&1){
                res = (res * base)%mod;
            }
            base = (base * base)%mod;
            exp = exp>>1;
        }

        return res;
    }

    long long modInverse(long long a, long long p){
        return power(a, p-2);
    }

    // long long nCr(long long n, long long r){
    //     long long ans = 1;
    //     for(long long i = 1;i<=r;i++){
    //         ans = (ans * (n - i + 1))/i;
    //         ans = ans%mod;
    //     }
    //     return ans%mod;
    // }
    
    long long nCr(long long n, long long r, vector<long long>&fact){
        return ((fact[n] * modInverse(fact[r], mod))%mod * modInverse(fact[n-r], mod))%mod;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        
        vector<long long> fact(n+1,1);

        for(int i = 2;i<=n;i++){
            fact[i] = (fact[i-1] * i)%mod;
        }

        long long ans = nCr(n - 1, k, fact);
        ans = (ans * m)%mod;
        ans = (ans * power(m - 1, n - 1 - k))%mod;

        return (int)ans;
    }
};