class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq;

        for(int x : nums){
            pq.push(x);
        }

        long long ans = 0;

        while(k--){
            long long val = pq.top();
            ans += val;
            pq.pop();
            pq.push((val+2)/3);
        }

        return ans;
        
    }
};