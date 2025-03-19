class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();

        int cnt = 0;

        for(int i = 2;i<n;i++){
            if(nums[i-2]==0){
                nums[i-2] ^= 1;
                nums[i-1] ^= 1;
                nums[i] ^= 1;

                cnt++;
            }
        }

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total==n){
            return cnt;
        }

        return -1;


        
    }
};