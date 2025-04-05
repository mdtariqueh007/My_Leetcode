class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int res = 0;

        for(int x: nums){
            res |= x;
        }

        return res<<(nums.size() - 1);
        
    }
};