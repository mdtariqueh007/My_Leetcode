class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int cntOnes = 0;
        int flips = 0;

        for(char c : s){
            if(c=='1'){
                cntOnes++;
            }
            else{
                flips = min(flips+1,cntOnes);
            }
        }

        return flips;
        
    }
};