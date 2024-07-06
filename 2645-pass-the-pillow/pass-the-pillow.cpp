class Solution {
public:
    int passThePillow(int n, int time) {
        int full_rounds = time / (n - 1);

        int extra = time % (n - 1);

        if(full_rounds%2==0){
            return extra + 1;
        }
        else{
            return n - extra;
        }
    }
};