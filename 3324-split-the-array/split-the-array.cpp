class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(int i : nums){
            mp[i]++;
        }
        
        int cnt = 0;
        
        for(auto it : mp){
            if(it.second>2){
                return false;
            }
            if(it.second==1){
                cnt++;
            }
        }
        
        if(cnt%2==0){
            return true;
        }
        
        return false;
        
    }
};