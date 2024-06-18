class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        priority_queue<pair<int,int>> pq;

        for(int i = 0;i<n;i++){
            pq.push({profit[i],difficulty[i]});
        }

        sort(worker.rbegin(),worker.rend());

        int maxProfit = 0;

        for(int i = 0;i<m;i++){
            

            while(!pq.empty() && pq.top().second>worker[i]){
                pq.pop();
            }

            if(!pq.empty()){
                maxProfit += pq.top().first;
            }
        }

        return maxProfit;


    }
};