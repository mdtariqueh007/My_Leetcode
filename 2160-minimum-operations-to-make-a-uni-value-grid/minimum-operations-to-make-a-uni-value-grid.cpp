class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> nums;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int commonNum = nums[n/2];

        int ans = 0;

        for(int num: nums){
            if(abs(num-commonNum)%x!=0){
                return -1;
            }

            ans += abs(num-commonNum)/x;

        }

        return ans;
        
    }
};