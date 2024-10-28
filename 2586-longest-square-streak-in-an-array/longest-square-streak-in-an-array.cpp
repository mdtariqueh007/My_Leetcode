class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        int n = nums.size();

        int maxStreak = 0;

        for(int num : nums){
            int sq = (int)sqrt(num);

            if(sq*sq==num && mp.find(sq)!=mp.end()){
                mp[num] = mp[sq] + 1;
            }
            else{
                mp[num] = 1;
            }

            maxStreak = max(maxStreak,mp[num]);
        }

        if(maxStreak<2){
            return -1;
        }

        return maxStreak;
        
    }
};