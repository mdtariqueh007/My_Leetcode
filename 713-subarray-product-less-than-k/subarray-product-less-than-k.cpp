class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int i = 0;
        int res = 0;
        int prod = 1;
        for(int j = 0;j<n;j++){
            prod = prod*nums[j];
            while(prod>=k) {
                prod = prod/nums[i];
                i++;
            }
            res += (j-i+1);
        }
        return res;
    }
};