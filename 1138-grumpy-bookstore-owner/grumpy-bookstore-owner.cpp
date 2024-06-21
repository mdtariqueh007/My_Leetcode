class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int cnt = 0;
        int n = grumpy.size();

        int res = 0;

        for(int i = 0;i<n;i++){
            if(!grumpy[i]){
                res += customers[i];
                customers[i] = 0;
            }
        }

        int currSum = 0;

        for(int i = 0;i<minutes;i++){
            currSum += customers[i];
        }

        int maxSum = currSum;

        for(int i = minutes;i<n;i++){
            currSum += customers[i];
            currSum -= customers[i-minutes];

            maxSum = max(maxSum,currSum);
        }

        res += maxSum;

        return res;

        
        
    }
};