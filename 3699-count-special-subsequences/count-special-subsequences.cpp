class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {

        unordered_map<double, long long> mp;

        long long ans = 0;

        int n = nums.size();

        for(int r = 4;r<n-2;r++){

            int q = r - 2;

            for(int p = 0;p<q - 1;p++){
                double rat = (1.0 * nums[p])/(1.0 * nums[q]);

                mp[rat]++;
            }



            for(int s = r + 2;s<n;s++){
                double rat = (1.0 * nums[s])/(1.0 * nums[r]);

                ans += mp[rat];
            }

        }

        return ans;


        
    }
};