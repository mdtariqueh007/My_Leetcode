class Solution {
public:
    int minOperations(vector<int>& nums) {


        int n = nums.size();

        int cnt = 0;

        for(int i = 0;i<n;i++){
            if(nums[i]==0 && i+2<n){
                nums[i] = 1;
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];

                cnt++;
            }
        }

        if(find(nums.begin(),nums.end(),0)!=nums.end()){
            return -1;
        }

        return cnt;

        
    }
};