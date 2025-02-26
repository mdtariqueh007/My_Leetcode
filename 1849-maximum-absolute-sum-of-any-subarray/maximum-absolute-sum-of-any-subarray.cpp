class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int ans = 0;

        int sum = 0;

        for(int x: nums){
            sum += x;

            if(sum>ans){
                ans = sum;
            }

            if(sum<0){
                sum = 0;
            }
        }

        sum = 0;

        for(int x: nums){

            sum += x;

            if(abs(sum)>ans){
                ans = abs(sum);
            }

            if(sum>0){
                sum = 0;
            }


        }

        return ans;
        
    }
};