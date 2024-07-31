class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int right = 0;

        int ans = 0;

        int num = 0; 

        while(right<n){
            while((nums[right]&num)!=0){
                num = num^nums[left];
                left++;
            }

            num = num | nums[right];
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
        
    }
};