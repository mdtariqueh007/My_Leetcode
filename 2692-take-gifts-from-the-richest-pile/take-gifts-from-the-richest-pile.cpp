class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int,vector<int>> pq;
        for(int i = 0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        for(int  i = 0;i<k;i++){
            int temp = pq.top();
            pq.pop();
            pq.push(floor(sqrt(temp)));
        }
        long long sum = 0;
        while(pq.empty()==false){
            sum += pq.top();
            pq.pop();
        }

        return sum;
        
    }
};