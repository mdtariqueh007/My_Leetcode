class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double,int>> ratio;

        for(int i = 0;i<n;i++){//O(n)
            ratio.push_back({wage[i]*1.0/quality[i]*1.0,quality[i]});
        }

        sort(ratio.begin(),ratio.end()); //O(nlogn)

        priority_queue<int> pq;

        double sum = 0.0;

        for(int i = 0;i<k-1;i++){ //O(klogk)
            pq.push(ratio[i].second);
            sum += ratio[i].second;
        }

        double ans = 1e9;

        for(int i = k-1;i<n;i++){//O(nlogk)
            pq.push(ratio[i].second);
            sum += ratio[i].second;
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }

            ans = min(ans,ratio[i].first*sum); 


        }

        return ans;
    }
};