class Solution {
    private:
    int solve(vector<int>&nums, int ind, int currXor){
        if(ind==nums.size()){
            return currXor;
        }

        int withElement = solve(nums,ind+1, currXor^nums[ind]);
        int withoutElement = solve(nums,ind+1, currXor);

        return withElement + withoutElement;
    }
public:
    int subsetXORSum(vector<int>& nums) {

        return solve(nums,0,0);
        
    }
};