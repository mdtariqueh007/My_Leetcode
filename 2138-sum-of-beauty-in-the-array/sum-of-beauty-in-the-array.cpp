class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        int n = nums.size();

        vector<int> maxi(n,0);
        vector<int> mini(n,1e9);

        maxi[0] = nums[0];

        for(int i = 1;i<n;i++){
            maxi[i] = max(maxi[i-1],nums[i]);
        }

        mini[n - 1] = nums[n-1];

        for(int i = n - 2;i>=0;i--){
            mini[i] = min(mini[i+1],nums[i]);
        }

        int res = 0;

        for(int i = 1;i<=n-2;i++){
            if(nums[i]>maxi[i-1] && nums[i]<mini[i+1]){
                res += 2;
            }
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                res++;
            }
        }

        return res;
        
    }
};