class Solution {
public:
    long long findScore(vector<int>& nums) {

        long long ans = 0;

        priority_queue<pair<long long,int>,vector<pair<long long, int>>, greater<>> pq;

        for(int i = 0;i<nums.size();i++){
            pq.push({nums[i], i});
        }

        vector<bool> marked(nums.size(), false);

        while(!pq.empty()){
            long long num = pq.top().first;
            int ind = pq.top().second;

            pq.pop();

            if(marked[ind]==false){
                ans += num;
                if(ind-1>=0){
                    marked[ind-1] = true;
                }

                if(ind+1<nums.size()){
                    marked[ind+1] = true;
                }
            }
        }

        return ans;
        
    }
};