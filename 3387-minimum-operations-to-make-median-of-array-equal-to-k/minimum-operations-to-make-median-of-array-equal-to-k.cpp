class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        int mid = n/2;
        
        
        if(nums[mid]==k){
            return 0;
        }
        
        else if(nums[mid]>k){
            long long op = 0;
            for(int e = mid;e>=0;e--){
                if(nums[e]>=k){
                    op += nums[e] -k;
                }else{
                    break;
                }
            }
            
            return op;
        }
        
        else{
            long long op = 0;
            
            for(int e = mid;e<n;e++){
                if(nums[e]<=k){
                    op += k - nums[e];
                }else{
                    break;
                }
            }
            
            return op;
        }
        
    }
};