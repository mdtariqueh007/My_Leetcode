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
            int outlier = sum - 2 * x;

            if(mp.find(outlier)!=mp.end() && mp[outlier]!=i){
                ans = max(ans, outlier);
            }
        }

        return ans;
        
    }
};