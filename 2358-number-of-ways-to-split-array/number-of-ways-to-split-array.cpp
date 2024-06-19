class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // vector<long long> prefix(n,0);

        // prefix[0] = nums[0];

        long long right = 0, left = 0;

        for(int i = 0;i<n;i++){
            right += nums[i];
        }

        int cnt = 0;

        for(int i = 0;i<n-1;i++){
            left += nums[i];
            
            right -= nums[i];
            
            if(left>=right){
                cnt++;
            }
        }

        return cnt;
    }
};