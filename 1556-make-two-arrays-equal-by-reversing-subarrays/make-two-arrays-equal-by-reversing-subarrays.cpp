class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int x : target){
            mp[x]++;
        }

        for(int x : arr){
            if(mp[x]==0){
                return false;
            }
            else{
                mp[x]--;
            }
        }

        return true;    }
};