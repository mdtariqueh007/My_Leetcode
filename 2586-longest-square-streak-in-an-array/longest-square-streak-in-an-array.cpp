class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {


        unordered_set<int> st(nums.begin(),nums.end());

        int maxStreak = 0;

        for(int num : nums){
            int currStreak = 0;
            long long currNum = num;

            while(st.find(currNum)!=st.end()){
                currStreak++;

                if(currNum*currNum>1e5){
                    break;
                }

                currNum *= currNum;
            }

            maxStreak = max(maxStreak,currStreak);

        }


        if(maxStreak<2){
            return -1;
        }

        return maxStreak;
        
    }
};