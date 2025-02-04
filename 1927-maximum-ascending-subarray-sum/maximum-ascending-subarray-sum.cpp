class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int sum = nums[0];
        int maxSum = sum;

        int n = nums.size();
        
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
        
    }
};