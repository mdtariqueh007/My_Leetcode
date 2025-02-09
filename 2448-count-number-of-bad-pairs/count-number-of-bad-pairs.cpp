class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt = 0;
        long long res = 0;

        long long n = nums.size();

        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int val = nums[i] - i;
            if(mp[val]>0){
                cnt += mp[val];
            }

            mp[val]++;
        }

        res = (n*(n-1))/2 - cnt;

        return res;
    }
};