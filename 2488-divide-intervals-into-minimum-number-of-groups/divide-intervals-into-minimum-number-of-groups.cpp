class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int cnt = 0;
        int ans = cnt;

        vector<pair<int,int>> vec;

        for(int i = 0;i<intervals.size();i++){
            vec.push_back({intervals[i][0],0});
            vec.push_back({intervals[i][1],1});
        }

        sort(vec.begin(),vec.end());

        for(int i = 0;i<vec.size();i++){
            if(vec[i].second==0){
                cnt++;
            }
            else{
                cnt--;
            }

            ans = max(ans,cnt);
        }

        return ans;
        
    }
};