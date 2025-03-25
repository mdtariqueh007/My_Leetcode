class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();

        int ans = 0;

        for(int i = 0;i<n;i++){
            int curr = 1;

            for(int j = i + 1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    curr++;
                }
                else{
                    break;
                }
            }

            ans = max(ans, curr);
        }

        for(int i = 0;i<n;i++){
            int curr = 1;

            for(int j = i + 1;j<n;j++){
                if(nums[j]<nums[j-1]){
                    curr++;
                }
                else{
                    break;
                }
            }

            ans = max(ans, curr);
        }

        return ans;


        
    }
};