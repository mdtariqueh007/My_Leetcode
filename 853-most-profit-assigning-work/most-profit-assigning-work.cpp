class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n = profit.size();

        vector<pair<int,int>> v;

        for(int i = 0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(),v.end());

        int sum = 0;

        int m = worker.size();

        for(int i = 0;i<m;i++){
            int maxProfit = 0;
            for(int j = 0;j<v.size();j++){
                if(v[j].first<=worker[i]){
                    maxProfit = max(maxProfit,v[j].second);
                }
                else{
                    break;
                }
            }
            sum += maxProfit;
        }

        return sum;
        
    }
};