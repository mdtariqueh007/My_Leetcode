class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n = profit.size();

        vector<pair<int,int>> v;

        for(int i = 0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(),v.end());

        for(int i = 1;i<n;i++){
            v[i].second = max(v[i].second,v[i-1].second);
        }

        int sum = 0;

        int m = worker.size();

        for(int i = 0;i<m;i++){
            int maxProfit = 0;
            int low = 0;
            int high = v.size() - 1;
            while(low<=high){
                int mid = low + (high - low)/2;

                if(v[mid].first<=worker[i]){
                    maxProfit = max(maxProfit,v[mid].second);
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            sum += maxProfit;
        }

        return sum;
        
    }
};