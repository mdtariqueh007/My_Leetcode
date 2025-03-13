class Solution {
    private:
    bool solve(int ind, vector<int>&nums, int cnt, int k, vector<int>&visited, int currSum, int targetSum){
        if(cnt==k-1){
            return true;
        }

        if(currSum==targetSum){
            return solve(0, nums, cnt + 1, k, visited, 0, targetSum);
        }

        for(int i = ind;i<nums.size();i++){
            if(visited[i] || currSum + nums[i]>targetSum){
                continue;
            }

            visited[i] = 1;

            if(solve(i + 1, nums, cnt, k, visited, currSum + nums[i], targetSum)){
                return true;
            }

            visited[i] = 0;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum%k!=0){
            return false;
        }

        int targetSum = totalSum/k;

        vector<int> visited(nums.size(), 0);

        return solve(0, nums, 0, k, visited, 0, targetSum);

        
        
    }
};