class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        map<int, int> mp;

        int left = 0;

        int n = nums.size();

        long long cnt = 0;

        for(int right = 0;right<n;right++){
            mp[nums[right]]++;

            while(mp.rbegin()->first - mp.begin()->first > 2){
                mp[nums[left]]--;

                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }

                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;

    }
};