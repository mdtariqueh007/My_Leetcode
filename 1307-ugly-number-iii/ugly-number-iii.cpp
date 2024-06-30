class Solution {

    private:
    long long lcm(long long a,long long b){
        return (a*b)/__gcd(a,b);
    }
    long long count(long long n,long long a,long long b,long long c){
        return n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) - n/lcm(a,c) + n/lcm(a,lcm(b,c));
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {

        int low = 1;
        int high = 2e9;

        int ans = high;
        while(low<=high){
            long long mid = low + (high - low)/2;

            if(count(mid,a,b,c)<n){
                
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;

        
    }
};