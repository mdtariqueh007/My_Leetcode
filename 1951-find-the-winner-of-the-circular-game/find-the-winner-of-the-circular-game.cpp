class Solution {
public:

    int myWin(int n,int k){
        if(n==1) return 0;
        else{
            return (myWin(n-1,k)+k)%n;
        }
    }

    int findTheWinner(int n, int k) {
        
        return myWin(n,k)+1;

    }
};