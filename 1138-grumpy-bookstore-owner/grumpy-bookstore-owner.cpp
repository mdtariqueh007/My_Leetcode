class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int currSatisfied = 0;

        for(int i = 0;i<minutes;i++){
            currSatisfied += customers[i] * grumpy[i];
        }

        int maxSatisfied = currSatisfied;

        int i = 0;
        int j = minutes;

        while(j<n){
            currSatisfied += customers[j] * grumpy[j];
            currSatisfied -= customers[i] * grumpy[i];

            maxSatisfied = max(maxSatisfied,currSatisfied);
            i++;
            j++;
        }

        for(int i = 0;i<n;i++){
            maxSatisfied += customers[i] * (1 - grumpy[i]);
        }

        return maxSatisfied;
    }
};