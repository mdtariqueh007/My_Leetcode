class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        long long pre = 1,suff = 1;
        int n = nums.size();
        long long res  = 0;
        for(int i = 0;i<n;i++){

            if(pre>INT_MAX || pre<INT_MIN){
                pre = 1;
            }
            if(suff>INT_MAX || suff<INT_MIN){
                suff = 1;
            }
            if(pre==0) pre = 1;
            if(suff==0) suff = 1;
            pre = pre*(long long)nums[i];
            suff = suff*nums[n-i-1];
            res = max(res,max(pre,suff));
        }

        return (int)res;
        
    }
};