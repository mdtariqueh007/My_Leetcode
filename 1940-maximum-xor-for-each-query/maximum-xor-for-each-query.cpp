class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int maxValue = 1<<maximumBit;

        maxValue--;

        vector<int> ans;

        int lastXor = 0;

        for(int i = 0;i<nums.size();i++){
            lastXor ^= nums[i];

            int k = lastXor^maxValue;

            ans.push_back(k);
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};