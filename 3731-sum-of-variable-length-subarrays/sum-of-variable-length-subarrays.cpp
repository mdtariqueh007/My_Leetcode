class Solution {
public:
    int subarraySum(vector<int>& nums) {

        int ans = 0;

        int n = nums.size();

        vector<int> prefix(n,0);

        prefix[0] = nums[0];

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = 0;i<nums.size();i++){
            int start = max(0, i - nums[i]);

            if(start==0){
                ans += prefix[i];
            }
            else{
                ans += (prefix[i] - prefix[start-1]);
            }
        }

        return ans;
        
    }
};