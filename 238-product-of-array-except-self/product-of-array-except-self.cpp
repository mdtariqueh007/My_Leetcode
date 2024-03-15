class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);
        int product = 1;
        ans[0] = product;
        for(int i = 1;i<n;i++){
            ans[i] = product*nums[i-1];
            product = ans[i];
        }
        product = 1;
        
        for(int i = n-2;i>=0;i--){
            ans[i] = ans[i]*product*nums[i+1];
            product = product*nums[i+1];
        }

        return ans;

        
        
    }
};