class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        long long ans = 0;
        long long odd = 0, even = 1;
        const int mod = 1e9 + 7;

        int sum = 0;

        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            if(sum%2){
                ans += even;
            }
            else{
                ans += odd;
            }

            if(sum%2){
                odd++;
            }
            else{
                even++;
            }

            ans = ans%mod;
        }

        return (int)ans;
        
    }
};