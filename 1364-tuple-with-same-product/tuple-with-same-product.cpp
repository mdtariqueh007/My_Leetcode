class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int n = nums.size();

        int cnt = 0;

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                int prod = nums[i] * nums[j];

                cnt += mp[prod];
                mp[prod]++;
            }
        }

        return cnt * 8;
        
    }
};