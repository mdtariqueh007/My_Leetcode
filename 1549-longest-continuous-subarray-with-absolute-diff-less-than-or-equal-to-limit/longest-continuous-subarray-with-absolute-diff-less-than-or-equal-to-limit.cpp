class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        multiset<int> mt;

        int n = nums.size();

        int left = 0;
        int res = 0;

        for(int right = 0;right<n;right++){
            mt.insert(nums[right]);

            while(*mt.rbegin() - *mt.begin()>limit){
                mt.erase(mt.find(nums[left]));
                left++;
            }

            res = max(res,right - left + 1);
        }

        return res;


        
    }
};