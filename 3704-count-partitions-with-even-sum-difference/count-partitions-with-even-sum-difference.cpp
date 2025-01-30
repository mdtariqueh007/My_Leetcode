class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;

        for(int i = 0;i<n;i++){
            totalSum += nums[i];
        }

        int currSum = 0;
        int cnt = 0;

        for(int i = 0;i<n-1;i++){
            currSum += nums[i];

            if(abs(currSum - (totalSum - currSum))%2==0){
                cnt++;
            }
        }

        return cnt;
        
    }
};