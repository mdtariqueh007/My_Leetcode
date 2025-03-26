class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {

        int n = nums.size();
        long long ans = 0;

        unordered_map<double,long long> mp;

        for(int r = 4;r<n-2;r++){
            int q = r - 2;

            for(int p = 0;p<q-1;p++){
                double ratio = (nums[p]*1.0)/(nums[q]*1.0);
                mp[ratio]++;
            }

            for(int s = r+2;s<n;s++){
                double ratio = (nums[s]*1.0)/(nums[r]*1.0);
                ans += mp[ratio];
            }
        }

        return ans;
        
    }
};