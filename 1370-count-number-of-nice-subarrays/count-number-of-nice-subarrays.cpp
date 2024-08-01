class Solution {
    private:
    int atMost(vector<int>&nums,int k){
        int n = nums.size();

        int i = 0;
        int j = 0;
        
        int ans = 0;

        int cnt = 0;

        while(j<n){
            if(nums[j]%2){
                cnt++;
            }

            while(cnt>k){
                if(nums[i]%2){
                    cnt--;
                }
                i++;
            }

            ans += (j - i + 1);

            j++;

        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums,k) - atMost(nums,k-1);

        
    }
};