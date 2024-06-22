class Solution {
    private int atMost(int[] nums,int k){
        int n = nums.length;

        int res = 0, curr = 0;

        int left = 0;

        for(int right=0;right<n;right++){
            curr += nums[right]&1;

            while(curr>k){
                curr -= nums[left]&1;

                left++;
            }

            res += right - left + 1;
        }

        return res;
    }
    public int numberOfSubarrays(int[] nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
}