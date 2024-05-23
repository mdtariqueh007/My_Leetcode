class Solution {
    private:
    int f(int ind,vector<int>&nums,int k,unordered_map<int,int>&mp){
        if(ind==nums.size()) return 0;

        int pick = 0,notPick = 0;
        if(mp[nums[ind]+k]==0 && mp[nums[ind]-k]==0){
            mp[nums[ind]]++;
            pick = 1 + f(ind+1,nums,k,mp);
            mp[nums[ind]]--;
        }
        notPick = f(ind+1,nums,k,mp);

        return pick + notPick;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        
        unordered_map<int,int> st;
        return f(0,nums,k,st);
    }
};