class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxi = *max_element(nums.begin(),nums.end());

        int cnt = 0;

        int ans = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=maxi){
                ans = max(ans,cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }

        ans = max(ans,cnt);

        return ans;
        
    }
};