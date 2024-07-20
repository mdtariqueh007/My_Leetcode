class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        priority_queue<int,vector<int>,greater<>> pq;

        for(int x  :arr){
            pq.push(x);
        }

        unordered_map<int,int> mp;

        int rank = 1;

        while(!pq.empty()){
            int val = pq.top();
            pq.pop();

            if(mp.find(val)==mp.end()){
                mp[val] = rank++;
            }
        }

        vector<int> ans;

        for(int x : arr)
        {
            ans.push_back(mp[x]);
        }

        return ans;
        
    }
};