    const int N = 1e6+10;
    vector<int> prime(N+1,1);
class Solution {
    private:
    void Seive(){
        prime[0]=prime[1] = 0;
        for(int i = 2;i<N;i++){
            if(prime[i]){
                for(long long j = (long long)i*i;j<N;j = j+i){
                    prime[j] = 0;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        Seive();
        vector<int> rangePrime;
        for(int i = left;i<=right;i++){
            if(prime[i]){
                rangePrime.push_back(i);
            }
        }
        if(rangePrime.size()<2){
            return {-1,-1};
        }
        int a = rangePrime[0],b = rangePrime[1];
        int mini = b-a;
        for(int i = 0;i<rangePrime.size()-1;i++){
            int currMin = rangePrime[i+1] - rangePrime[i];
            if(currMin<mini){
                mini = currMin;
                a = rangePrime[i];
                b = rangePrime[i+1];
            }
        }

        return {a,b};
    }
};