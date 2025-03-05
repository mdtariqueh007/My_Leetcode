class Solution {
public:
    long long coloredCells(int n) {

        long long ans = 1;
        long long toAdd = 4;

        while(--n){
            ans += toAdd;

            toAdd += 4;

        }

        return ans;
        
        
    }
};