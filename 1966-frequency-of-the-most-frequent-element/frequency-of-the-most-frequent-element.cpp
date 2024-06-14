class Solution {
    private:
    void countSort(vector<int>&nums){
        int maxi = *max_element(nums.begin(),nums.end());

        vector<int> count(maxi + 1,0);

        for(int x : nums){
            count[x]++;
        }

        int ind = 0;

        for(int i = 0;i<=maxi;i++){
            while(count[i]>0){
                nums[ind] = i;
                ind++;
                count[i]--;
            }
        }

    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());

        countSort(nums);

        #define int long long

        int n = nums.size();

        int res = 0;

        long long curr = 0;

        int left = 0;

        for(int right = 0;right<n;right++){
            curr += nums[right];

            int target = nums[right];

            if((right - left + 1) * target - curr  > k){
                curr -= nums[left];
                left++;
            }

            res = max(res,right - left + 1);
        }

        #undef int

        return n - left;
    }
};