class Solution {
public:
    int minBitFlips(int start, int goal) {

        int target = start^goal;

        int cnt = 0;

        for(int i = 0;i<32;i++){
            if((target&(1<<i))!=0){
                cnt++;
            }
        }

        return cnt;
        
    }
};