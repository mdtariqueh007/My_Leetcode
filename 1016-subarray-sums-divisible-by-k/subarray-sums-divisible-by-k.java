class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;

        int[] sumMod = new int[k];

        sumMod[0] = 1;

        int currSum = 0;

        int res = 0;

        for(int x : nums){
            currSum = (currSum + x%k + k)%k;

            res += sumMod[currSum];

            sumMod[currSum]++;
        }

        return res;
    }
}