class Solution {
    public int[] singleNumber(int[] nums) {

        int n = nums.length;

        int xr = 0;

        for(int x  :nums){
            xr = xr^x;
        }

        int mask = xr & (-xr);

        int[] res = new int[2];

        for(int x : nums){
            if((mask & x)==0){
                res[0] ^= x;
            }
            else{
                res[1] ^=x;
            }
        }

        return res;
        
    }
}