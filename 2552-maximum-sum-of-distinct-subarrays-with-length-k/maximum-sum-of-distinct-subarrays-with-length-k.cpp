class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int n = nums.size();

        long long ans = 0, sum = 0;

        int left = 0;

        for(int right = 0;right<n;right++){
            mp[nums[right]]++;
            sum += nums[right];

            if(k==(right-left+1)){
                if(mp.size()==k){
                    ans = max(ans,sum);
                }
                sum -= nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
        }

        return ans;
        
    }
};