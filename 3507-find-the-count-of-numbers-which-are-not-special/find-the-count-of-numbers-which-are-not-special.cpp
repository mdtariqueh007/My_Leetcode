class Solution {
public:
    int nonSpecialCount(int l, int r) {

        int n = (int)sqrt(r);

        vector<bool> isPrime(n+1,true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j = i*i;j<=n;j+=i){
                    isPrime[j] = false;
                }
            }
        }

        int cnt = 0;

        for(int i = 2;i<=n;i++){
            if(isPrime[i]){
                int sq = i * i;
                if(sq>=l && sq<=r){
                    cnt++;
                }
            }
        }

        int total = r - l + 1;

        return total - cnt;
        
    }
};