class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        

        int cntGreater = 0;

        vector<bool> isPresent(101, false);

        for(int x: nums){
            if(x>k && !isPresent[x]){
                cntGreater++;
                isPresent[x] = true;
            }
            else if(x<k){
                return -1;
            }
        }

        return cntGreater;
        
    }
};