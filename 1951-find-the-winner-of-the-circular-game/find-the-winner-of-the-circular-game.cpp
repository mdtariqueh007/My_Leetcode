class Solution {
    private:
    int findWinnerInd(int n,int k){
        if(n==1){
            return 0; 
        }

        int ind = findWinnerInd(n-1,k);
        ind = (ind + k)%n;

        return ind;
    }
public:
    int findTheWinner(int n, int k) {
        
        int res = findWinnerInd(n,k);

        return res + 1;
    }
};