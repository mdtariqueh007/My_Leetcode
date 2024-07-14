class Solution {
    public int longestConsecutive(int[] nums) {

        Arrays.sort(nums);
        int lastSmaller = Integer.MIN_VALUE;

        int cnt = 0;

        int longest = 0;


        for(int i = 0;i<nums.length;i++){
            if(nums[i]-1==lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i]==lastSmaller){
                continue;
            }
            else if(nums[i]!=lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }

            longest = Math.max(longest,cnt);
        }

        return longest;

    }
}