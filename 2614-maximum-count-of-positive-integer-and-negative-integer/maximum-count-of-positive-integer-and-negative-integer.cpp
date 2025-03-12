class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();
        
        int pos = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        pos = n - pos;
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        return max(pos, neg);
    }
};