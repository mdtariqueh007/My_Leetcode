class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1){
            return 1;
        }

        int p = primes.size();
        
        vector<int> ind(p,1);

        vector<int> arr(n+1);

        arr[1] = 1;

        for(int i = 2;i<=n;i++){
            long long minUglyNum = INT_MAX;

            for(int j = 0;j<p;j++){

                long long uglyNum = arr[ind[j]] * (long long)primes[j];

                minUglyNum = min(minUglyNum,uglyNum );
                
            }

            

            arr[i] = minUglyNum;

            for(int j = 0;j<p;j++){
                if(minUglyNum == (arr[ind[j]]  * (long long)primes[j])){
                    ind[j]++;
                }
            }

        }

        return arr[n];
    }
};