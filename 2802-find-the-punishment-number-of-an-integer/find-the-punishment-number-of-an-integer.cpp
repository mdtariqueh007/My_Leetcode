class Solution {
    private:
    bool canPartition(string &num, int target, int ind, int currSum){
        if(ind==num.size()){
            return currSum==target;
        }

        int sum = 0;

        for(int j = ind;j<num.size();j++){
            sum = sum*10 + (num[j] - '0');
            if(canPartition(num,target,j+1, currSum+sum)){
                return true;
            }
        }

        return false;
    }
public:
    int punishmentNumber(int n) {

        int ans = 0;

        for(int i = 1;i<=n;i++){
            int square = i * i;
            string sqStr = to_string(square);

            if(canPartition(sqStr, i, 0, 0)){
                ans += square;
            }
        }

        return ans;
        
    }
};