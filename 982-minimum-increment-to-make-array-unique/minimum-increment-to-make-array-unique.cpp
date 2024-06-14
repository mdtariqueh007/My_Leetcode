class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        int maxi = 0, res = 0;

        for(int i = 0;i<n;i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]++;
                maxi = max(maxi,nums[i]);
            }
            else{
                res += (maxi + 1 - nums[i]);
                mp[maxi+1]++;
                maxi = maxi + 1;
            }
            
        }

        return res;
        
    }
};