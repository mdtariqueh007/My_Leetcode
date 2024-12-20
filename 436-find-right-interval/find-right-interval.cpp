class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        vector<pair<int,int>> start;

        for(int i = 0;i<intervals.size();i++){
            start.push_back({intervals[i][0], i});
        }

        sort(start.begin(), start.end());

        vector<int> ans;

        for(auto it: intervals){
            int end = it[1];

            pair<int,int> a = {end,0};

            int ind = lower_bound(start.begin(), start.end(), a) - start.begin();

            if(ind==start.size()){
                ans.push_back(-1);
            } 
            else{
                ans.push_back(start[ind].second);
            }
        }

        return ans;
        
    }
};