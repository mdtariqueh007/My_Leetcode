class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        int n = nums.size();

        vector<int> cnt(32,0);

        for(int i = 0;i<32;i++){
            for(auto x: nums){
                cnt[i] += (x & (1<<i))==0?0:1;
            }
        }

        int ans = 0;

        for(int k: cnt){
            ans += (k * (n-k));
        }

        return ans;
        
    }
};