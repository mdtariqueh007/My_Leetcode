class Solution {
    private:
    int atMost(vector<int>&nums,int k){
        int i = 0;
        int n = nums.size();
        int res = 0;
        unordered_map<int,int> mp;
        for(int j = 0;j<n;j++){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]); //important as we have to erase if it becomes 0
                }
                i++;
            }
            res += (j-i+1);
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};