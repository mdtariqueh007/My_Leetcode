class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();

        long long cnt = 0;

        unordered_map<int,long long> mp;

        for(int i = 0;i<n;i++){
            int rem = (hours[i]%24 + 24)%24;

            cnt += mp[(24-rem)%24];

            mp[rem]++;
        }
        return cnt;
    }
};