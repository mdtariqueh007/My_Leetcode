class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> pq;

        for(int x : nums){
            if(pq.size()<k){
                pq.push(x);
            }
            else{
                if(pq.top()<x){
                    pq.pop();
                    pq.push(x);
                }
            }
        }   

        return pq.top();
    }
};