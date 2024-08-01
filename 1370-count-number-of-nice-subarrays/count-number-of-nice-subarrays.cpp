class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;

        int i = 0;
        int j = 0;
        int ind = 0;

        int ans = 0;

        while(j<n){
            if(nums[j]%2){
                cnt++;
            }

            while(cnt>k){
                if(nums[i]%2){
                    cnt--;
                }
                i++;
                ind = i;
            }

            while(i<j && nums[i]%2==0){
                
                i++;
            }

            if(cnt==k){
                ans += (i - ind) + 1;
            }

            j++;
        }

        return ans;
    }
};