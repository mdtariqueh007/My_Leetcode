class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int x = nums[0];

        int cnt = 0, n = nums.size();

        for(int num: nums){
            if(num==x){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt==0){
                x = num;
                cnt = 1;
            }
        }

        int xCount = 0;

        for(int num: nums){
            if(num==x){
                xCount++;
            }
        }

        cnt = 0;

        for(int i = 0;i<n-1;i++){
            if(nums[i]==x){
                cnt++;
            }
            int remCnt = xCount - cnt;
            if(cnt*2>i+1 && remCnt*2>n-i-1){
                return i;
            }
        }

        return -1;


        
    }
};