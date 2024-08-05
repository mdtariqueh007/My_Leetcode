class Solution {
    private:
    bool isPoss(vector<int>&nums,int mid,int maxOperations){
        int n = nums.size();

        int op = 0;

        for(int i = 0;i<n;i++){
            int req = (nums[i] + mid - 1)/mid - 1;

            op += req;

            if(op>maxOperations){
                return false;
            }
        }

        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
        int high = 1e9;

        int ans = 1e9;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPoss(nums,mid,maxOperations)){
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