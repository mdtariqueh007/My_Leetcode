class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        

        int n = numBottles;

        int ans = n;

        int empty = n;

        while(empty>=numExchange){

            ans += empty/numExchange;

            empty = empty - (empty/numExchange) * numExchange + empty/numExchange;

        }

        return ans;


    }
};