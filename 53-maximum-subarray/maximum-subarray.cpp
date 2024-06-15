class Solution {
    private:
    int helper(vector<int>&nums,int l,int r){
        if(l==r){
            return nums[l];
        }

        int mid = l + (r-l)/2;

        int leftSum = -1e6, rightSum = -1e6;

        int leftMaxSum = helper(nums,l,mid);
        int rightMaxSum = helper(nums,mid+1,r);
        int sum = 0;
        for(int i = mid;i>=l;i--){
            sum += nums[i];
            leftSum = max(leftSum,sum);
        }
        sum = 0;
        for(int i = mid+1;i<=r;i++){
            sum += nums[i];
            rightSum = max(rightSum,sum);
        }

        return max(max(leftMaxSum,rightMaxSum),leftSum+rightSum);

    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};