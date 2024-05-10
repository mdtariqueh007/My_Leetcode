class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<double,pair<int,int>>> pq;

        int n = arr.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                double val = (arr[i]*1.0)/(arr[j]*1.0);
                pq.push({val,{arr[i],arr[j]}});

                if(pq.size()>k){
                    pq.pop();
                }
            }
        }

        auto ans = pq.top();

        int num = ans.second.first;
        int deno = ans.second.second;

        return {num,deno};
        
    }
};