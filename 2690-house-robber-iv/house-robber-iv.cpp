class Solution {
    private:
    bool isPossible(vector<int>&nums, int mid, int k){
        int cnt = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }

        return cnt>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = 1e9;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};