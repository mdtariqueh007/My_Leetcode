class Solution {
public:
    int pivotInteger(int n) {

        int sum = (n*(n+1))/2;

        int sq = sqrt(sum);

        if(sum==sq*sq){
            return sq;
        }

        return -1;
        
    }
};