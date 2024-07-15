class Solution {
    public int minSubArrayLen(int target, int[] nums) {

        int n = nums.length;

        int left = 0;

        int res = (int)1e9;

        int currSum = 0;

        for(int right = 0;right<n;right++){
            currSum += nums[right];
            while(currSum>=target){
                res = Math.min(res, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        return res==(int)1e9?0:res;
        
    }
}