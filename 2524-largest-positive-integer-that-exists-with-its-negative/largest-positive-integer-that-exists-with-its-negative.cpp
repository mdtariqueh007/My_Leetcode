class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int ans = -1;

        for(int num: nums){
            if(num>0){
                if(st.find(-num)!=st.end()){
                    ans = max(ans,num);
                }
            }
        }

        return ans;
    }
};