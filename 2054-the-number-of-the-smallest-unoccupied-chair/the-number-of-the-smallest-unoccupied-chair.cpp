class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        vector<pair<int,pair<int,int>>> vec;

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i = 0;i<times.size();i++){
            vec.push_back({times[i][0],{1,i}});
            vec.push_back({times[i][1],{0,i}});
        }

        sort(vec.begin(),vec.end());

        int chair = 0;

        unordered_map<int,int> mp;

        for(int i = 0;i<vec.size();i++){
            int index = vec[i].second.second;

            if(vec[i].second.first==1){
                if(pq.empty()){
                    mp[index] = chair;
                    chair++;
                }
                else{
                    mp[index] = pq.top();
                    pq.pop();
                }
            }
            else{
                pq.push(mp[index]);
            }

            
        }

        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }

        // while(!pq.empty()){
        //     cout<<pq.top()<<"\n";
        //     pq.pop();
        // }

        return mp[targetFriend];

        


        
    }
};