class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        long long ans = 0;

        sort(nums.begin(),nums.end());

        int n = nums.size();

        for(int i = 0;i<n;i++){

            int low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int high = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1) - nums.begin();

            ans += 1LL*(high - low);

        }

        return ans;

        
        
    }
};