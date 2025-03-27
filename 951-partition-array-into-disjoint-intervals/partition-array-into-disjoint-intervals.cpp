class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixMax(n), suffixMin(n);

        prefixMax[0] = nums[0];
        suffixMin[n-1] = nums[n-1];

        for(int i = 1;i<n;i++){
            prefixMax[i] = max(nums[i], prefixMax[i-1]);
            suffixMin[n-i-1] = min(nums[n-i-1], suffixMin[n-i]);
        }

        for(int i = 0;i<n-1;i++){
            if(prefixMax[i]<=suffixMin[i+1]){
                return i + 1;
            }
        }

        return -1;
        
    }
};