class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int drunk = 0;

        drunk = numBottles;
        int empty = drunk;

        int full = 0;

        while(empty>0){
            if(empty>=numExchange){
                full++;
                empty -= numExchange;
                numExchange++;
            }
            else{
                drunk += full;
                empty += full;
                full = 0;
                if(empty<numExchange){
                    break;
                }
            }

            
        }

        drunk += full;
        

        return drunk;
        
    }
};