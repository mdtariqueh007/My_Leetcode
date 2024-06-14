class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        #define int long long

        int n = nums.size();

        int res = 0;

        long long curr = 0;

        int left = 0;

        for(int right = 0;right<n;right++){
            curr += nums[right];

            int target = nums[right];

            while((right - left + 1) * target - curr  > k){
                curr -= nums[left];
                left++;
            }

            res = max(res,right - left + 1);
        }

        #undef int

        return res;
    }
};