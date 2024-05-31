class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int n = nums.size();

        vector<int> res;

        long long int xr = 0;

        for(int i = 0;i<n;i++){
            xr = xr^nums[i];
        }

        int mask = xr&(-xr);

        int bucket1 = 0, bucket2 = 0;

        for(int i = 0;i<n;i++){
            if(mask & nums[i]){
                bucket1 = bucket1^nums[i];
            }else{
                bucket2 = bucket2^nums[i];
            }
        }

        res.push_back(bucket1);
        res.push_back(bucket2);

        return res;
        
    }
};