class Solution {
    public int numberOfSubarrays(int[] nums, int k) {

        int n = nums.length;

        Map<Integer,Integer> mp = new HashMap<>();

        int currSum = 0, res = 0;

        mp.put(currSum,1);

        for(int i = 0;i<n;i++){
            currSum += nums[i]%2;

            if(mp.containsKey(currSum-k)){
                res += mp.get(currSum-k);
            }

            mp.put(currSum,mp.getOrDefault(currSum,0) + 1);
        }

        return res;


        
    }
}