class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();

        long long ans = 0, imax = 0, dmax = 0;

        for(int k = 0;k<n;k++){
            ans = max(ans, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, (long long)nums[k]);
        }

        return ans;
        
    }
};