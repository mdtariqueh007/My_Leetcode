class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0;i<n;i++){
            nums.push_back(nums[i]);
        }

        int cnt = 0;

        for(int i = 0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
        }

        int cnt0 = 0;

        for(int i = 0;i<cnt;i++){
            if(nums[i]==0){
                cnt0++;
            }
        }

        int ans = cnt0;

        for(int i = cnt;i<2*n-1;i++){
            if(nums[i]==0){
                cnt0++;
            }
            if(nums[i - cnt]==0){
                cnt0--;
            }

            ans = min(ans,cnt0);
        }

        return ans;
        
    }
};