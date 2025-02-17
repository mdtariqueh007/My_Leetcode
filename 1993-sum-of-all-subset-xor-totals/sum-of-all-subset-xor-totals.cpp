class Solution {
    private:
    void generateSubsets(vector<int>&nums, int ind, vector<int> subset, vector<vector<int>>&subsets){
        if(ind==nums.size()){
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[ind]);
        generateSubsets(nums,ind+1, subset, subsets);
        subset.pop_back();
        generateSubsets(nums,ind+1, subset, subsets);
    }
public:
    int subsetXORSum(vector<int>& nums) {

        vector<vector<int>> subsets;

        generateSubsets(nums, 0, {}, subsets);

        int ans = 0;

        for(auto& subset: subsets){
            int xr = 0;
            for(int num: subset){
                xr ^= num;
            }
            ans += xr;
        }

        return ans;
        
    }
};