class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        int total = 0;

        vector<pair<int,int>> temp;

        for(int i = 0;i<n;i++){
            temp.push_back({difficulty[i],profit[i]});
        }

        sort(temp.begin(),temp.end());
        sort(worker.begin(),worker.end());

        int maxProfit = 0;
        int j = 0;
        for(int i = 0;i<m;i++){

            while(j<n && worker[i]>=temp[j].first){
                maxProfit = max(maxProfit,temp[j].second);
                j++;
            }

            total += maxProfit;
        }

        return total;
    }
};