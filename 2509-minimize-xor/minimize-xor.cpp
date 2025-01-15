class Solution {
    private:
    bool isSet(int x, int bit){
        return (x & (1<<bit));
    }
    void setBit(int &x, int bit){
        x = (x | (1<<bit));
    }
    void unsetBit(int &x, int bit){
        x = x & (~(1<<bit));
    }
public:
    int minimizeXor(int num1, int num2) {

        int ans = num1;

        int reqSetBits = __builtin_popcount(num2);
        int setBits = __builtin_popcount(ans);

        int currBit = 0;

        while(setBits < reqSetBits){
            if(!isSet(ans, currBit)){
                setBit(ans, currBit);
                setBits++;
            }
            currBit++;
        }

        while(setBits > reqSetBits){
            if(isSet(ans, currBit)){
                unsetBit(ans, currBit);
                setBits--;
            }
            currBit++;
        }


        return ans;
        
    }
};