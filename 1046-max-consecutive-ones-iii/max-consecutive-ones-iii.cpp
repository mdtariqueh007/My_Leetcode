class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int res = 0;
        int count = 0;
        for(int j= 0;j<n;j++){
            if(nums[j]==0){
                count++;
            }
            if(count>k){
                if(nums[i]==0) count--;
                i++;
            }
            if(count<=k)
                res = max(res,j-i+1);
        }

        return res;
        
    }
};