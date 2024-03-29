class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long cnt = 0;
        
        long long n = nums.size();
        
        int left = 0;
        
        int maxEle = *max_element(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        
        for(int right = 0;right<n;right++){
            mp[nums[right]]++;
            
            while(mp[maxEle]>=k){
                mp[nums[left]]--;
                left++;
            }
            
            cnt += (right-left+1);
        }
        
        long long res  = (n*(n+1))/2;
        
        res = res - cnt;
        
        return res;
        
    }
};