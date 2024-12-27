class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int n = values.size();

        priority_queue<int> pq;

        int ans = 0;

        for(int i = 0;i<n;i++){
            if(!pq.empty()){
                ans = max(ans, pq.top() + values[i] - i);
            }

            pq.push(values[i] + i);
        }

        return ans;
        
    }
};