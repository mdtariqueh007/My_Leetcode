class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int increasingLength = 1, decreasingLength = 1;

        int maxLength = 1;

        for(int i = 0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                increasingLength++;
                decreasingLength = 1;
            }
            else if(nums[i+1]<nums[i]){
                decreasingLength++;
                increasingLength = 1;
            }
            else{
                increasingLength = 1;
                decreasingLength = 1;
            }

            maxLength = max(maxLength, max(increasingLength, decreasingLength));
        }

        return maxLength;
        
    }
};