class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();
        if(n<=4) return 0;

        partial_sort(nums.begin(),nums.begin() + 4,nums.end());

        nth_element(nums.begin() + 4,nums.begin() + n - 4 , nums.end());

        sort(nums.begin() + n - 4 ,nums.end());

        int ans = nums[n-1] - nums[3];
        ans = min(ans,nums[n-4] - nums[0]);
        ans = min(ans,nums[n-3] - nums[1]);
        ans = min(ans,nums[n-2] - nums[2]);

        return ans;

        
        
    }
};