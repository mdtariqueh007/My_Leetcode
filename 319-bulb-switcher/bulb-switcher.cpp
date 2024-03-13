class Solution {
public:
    int bulbSwitch(int n) {

        int cnt = 0;

        for(int i = 1;i<=n;i++){
            int sq = sqrt(i);

            if(sq*sq==i){
                cnt++;
            }
        }  

        return cnt;
    }
};