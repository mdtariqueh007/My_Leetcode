class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {

        int n = nums.size();

        long long res = 1;

        int size = 1;

        for(int i = 1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                size++;
            }else{
                size = 1;
            }

            res += size;
        }

        return res;
        
    }
};