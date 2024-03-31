class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;

        int left = 0;

        int miniIndex = -1;
        int maxiIndex = -1;

        for(int right = 0;right<nums.size();right++){
            int val = nums[right];

            if(val<minK || val>maxK){
                left = right + 1;
                miniIndex = -1;
                maxiIndex = -1;
            }else{
                if(val==minK){
                    miniIndex = right;
                }
                if(val==maxK){
                    maxiIndex = right;
                }

                res += max(0,min(miniIndex,maxiIndex)-left+1);
            }


        }

        return res;
    }
};