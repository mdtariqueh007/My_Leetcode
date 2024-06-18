class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();

        int m = worker.size();

        int maxProfit = 0;

        for(int i = 0;i<m;i++){
            int curr = 0;
            for(int j = 0;j<n;j++){
                if(difficulty[j]<=worker[i]){
                    curr = max(curr,profit[j]);
                }
            }

            maxProfit += curr;
        }

        return maxProfit;


    }
};