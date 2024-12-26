class Solution {
public:


    int findWays(vector<int>& nums,int target,int i){
        if(target==0 && i==nums.size())
            return 1;
        else if(i==nums.size()) return 0;

        return findWays(nums,target-nums[i],i+1)+findWays(nums,target+nums[i],i+1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return findWays(nums,target,0);
    }
};