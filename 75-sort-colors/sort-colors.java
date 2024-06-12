class Solution {
    public void sortColors(int[] nums) {

        int low = 0, mid = 0, high = nums.length - 1;

        while(mid<=high){
            if(nums[mid]==0){
                // swap(nums[mid],nums[low]);
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                // swap(nums[mid],nums[high]);
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }
        }
        
    }
}