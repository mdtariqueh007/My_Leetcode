class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;

        int prefixZeros = 0;

        int sum = 0;
        int cnt = 0;

        while(j<n){
            sum += nums[j];

            while(i<j && (nums[i]==0 || sum>goal)){


                if(nums[i]==0){
                    prefixZeros++;
                }
                else{
                    prefixZeros = 0;
                }

                sum -= nums[i];
                i++;
            }

            if(sum==goal){
                cnt += 1 + prefixZeros;
            }
            j++;
        }

        return cnt;


    }
};