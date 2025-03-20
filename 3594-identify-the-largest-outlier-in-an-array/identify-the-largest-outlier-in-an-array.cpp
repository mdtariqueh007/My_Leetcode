class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {

        int n = nums.size();

        int ans = -1e9;

        unordered_map<int, int> mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]] = i;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = 0;i<n;i++){
            int x = nums[i];
            int ele2 = sum - x;
            if(ele2&1){
                continue;
            }

            ele2 /= 2;

            if(mp.find(ele2)!=mp.end() && mp[ele2]!=i){
                ans = max(ans, x);
            }
        }

        return ans;
        
    }
};