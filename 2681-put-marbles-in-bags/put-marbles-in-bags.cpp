class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        int n = weights.size();
        long long maxi = weights[0]+weights[n-1];
        long long mini = weights[0]+weights[n-1];

        vector<long long> adjSum;
        for(int i = 0;i<n-1;i++){
            adjSum.push_back(weights[i]+weights[i+1]);
        }
        sort(adjSum.rbegin(),adjSum.rend());

        for(int i = 0;i<k-1;i++){
            maxi= maxi + adjSum[i];
            mini = mini + adjSum.back();
            adjSum.pop_back();
        }

        return maxi-mini;
        
    }
};