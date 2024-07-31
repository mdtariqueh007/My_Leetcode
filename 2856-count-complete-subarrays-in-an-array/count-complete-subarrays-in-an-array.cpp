class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());

        int k = st.size();

        int n = nums.size();

        int i = 0;
        int j = 0;
        int ind = 0;

        unordered_map<int,int> mp;

        int ans = 0;

        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
                ind = i;
            }

            while(mp[nums[i]]>1){
                mp[nums[i]]--;
                i++;
            }

            if(mp.size()==k){
                ans += (i - ind) + 1;
            }

            j++;
        }

        return ans;


    }
};