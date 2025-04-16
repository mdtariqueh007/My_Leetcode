class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int n = nums.size();

        long long ans = 0;

        // for(int i = 0;i<n;i++){
        //     unordered_map<int, int> mp;
        //     long long pairs = 0;
        //     for(int j = i;j<n;j++){
        //         pairs += mp[nums[j]];
        //         mp[nums[j]]++;
        //         if(pairs>=k){
        //             ans++;
        //         }
        //     }
        // }

        unordered_map<int, int> mp;
        long long pairs = 0;

        int right = -1;

        for(int left = 0;left<n;left++){
            while(pairs<k && right+1<n){
                right++;
                pairs += mp[nums[right]];
                mp[nums[right]]++;
            }
            if(pairs>=k){
                ans += (n - right);
            }
            mp[nums[left]]--;
            pairs -= mp[nums[left]];
        }

        return ans;
        
    }
};