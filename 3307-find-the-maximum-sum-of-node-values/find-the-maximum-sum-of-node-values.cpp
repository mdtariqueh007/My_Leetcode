class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        long long idealSum = 0;

        long long minLoss = 1e9;

        int count = 0;

        for(int i = 0;i<n;i++){
            if((nums[i]^k)>nums[i]){
                idealSum += (nums[i]^k);
                count++;
            }else{
                idealSum += nums[i];
            }

            minLoss = min(minLoss,abs(nums[i]*1LL-(nums[i]^(k*1LL))));
        }  

        long long ans = idealSum;

        if(count%2){
            ans = ans - minLoss;
        }

        long long initialSum = 0;

        // for(int i: nums){
        //     initialSum += i;
        // }

        // if(initialSum>ans){
        //     return initialSum;
        // }

        return ans;
    }
};