class Solution {
    private:
    bool solve(int n, int power){
        if(n==0){
            return true;
        }

        if(pow(3, power)>n){
            return false;
        }

        bool addPower = solve(n - pow(3, power), power + 1);
        bool skipPower = solve(n, power + 1);

        return addPower || skipPower;
    }
public:
    bool checkPowersOfThree(int n) {

        return solve(n, 0);
        
    }
};