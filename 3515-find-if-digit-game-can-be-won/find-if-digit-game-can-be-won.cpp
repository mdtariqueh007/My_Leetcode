class Solution {
public:
    int cntDig(int n){
        return floor(log10(n)+1);
    }
    bool canAliceWin(vector<int>& nums) {

        int singleSum = 0, doubleSum = 0, totalSum = 0;

        for(int x : nums){
            int dig = cntDig(x);

            if(dig==1){
                singleSum += x;
            }
            else if(dig==2){
                doubleSum += x;
            }

            totalSum += x;
        }

        return (singleSum>(totalSum-singleSum) || doubleSum>(totalSum-doubleSum));

        
        
    }
};