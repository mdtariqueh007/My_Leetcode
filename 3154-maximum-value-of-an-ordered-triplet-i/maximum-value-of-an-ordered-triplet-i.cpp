class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        
        long long maxi = INT_MIN;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k= j+1;k<n;k++){
                    long long val = (long long)(nums[i] - nums[j]) * (long long)nums[k];
                    if(val>=0){
                        maxi = max(val,maxi);
                    }
                }
            }
        }
        
        if(maxi==INT_MIN) return 0;
        
        return maxi;
        
    }
};