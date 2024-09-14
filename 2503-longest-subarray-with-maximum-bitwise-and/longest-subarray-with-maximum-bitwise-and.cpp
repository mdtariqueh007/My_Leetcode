class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi, ans, cnt;
        maxi = ans = cnt = 0;

        for(int num: nums){
            if(num>maxi){
                maxi = num;
                ans = cnt = 0;
            }

            if(maxi==num){
                cnt++;
            }
            else{
                cnt = 0;
            }

            ans = max(ans,cnt);
        }

        return ans;

    }
};