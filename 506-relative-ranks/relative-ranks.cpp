class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i = 0;i<score.size();i++){
            pq.push({score[i],i});
        }

        vector<string> ans(score.size(), "");
        int  i = 0;
        while(pq.empty()==false){
            pair<int,int> temp = pq.top();
            if(i==0){
                ans[temp.second] = "Gold Medal";
            }
            else if(i==1){
                ans[temp.second] = "Silver Medal";
            } 
            else if(i==2){
                ans[temp.second] = "Bronze Medal";
            }
            else{
                ans[temp.second] = to_string(i+1);
            }
            i++;
            pq.pop();
        }

        return ans;

    }
};