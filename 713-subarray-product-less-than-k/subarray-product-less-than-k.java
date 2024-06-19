class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int cnt = 0;

        int n = nums.length;

        int lastFound = -1;

        for(int i = 0;i<n;i++){
            long product = 1;
            for(int j = i;j<n;j++){
                product *= nums[j];
                if(product<k){
                    cnt++;
                    
                }
                else{
                   break;
                }
            }
        }

        return cnt;
    }
}