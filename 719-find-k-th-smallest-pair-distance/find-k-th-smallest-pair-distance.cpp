class Solution {
    private:
    int check(vector<int>&nums,int mid){
        int i = 0;
        int j = 1;

        int pairCount = 0;

        while(j<nums.size()){
            while(nums[j]-nums[i]>mid){
                i++;
            }

            pairCount += (j - i);
            j++;
        }

        return pairCount;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        int low = 0;
        int high = nums[n - 1] - nums[0];

        int ans = high;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(check(nums,mid)<k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
        
    }
};