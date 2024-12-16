class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

       priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;

       for(int i = 0;i<nums.size();i++){
            pq.push({nums[i], i});
       } 

       while(k--){
            auto it = pq.top();
            pq.pop();

            int i = it.second;

            nums[i] *= multiplier;

            pq.push({nums[i], i});
       }

       return nums;
       
    }
};