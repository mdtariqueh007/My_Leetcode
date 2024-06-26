class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        mp.insert({0,0});
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(mp.count(sum%k)==0){
                mp[sum%k] = i + 1;
            }
            else{
                if(mp[sum%k]<i){
                    return true;
                }
            }
        }

        return false;
        
    }
};