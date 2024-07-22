class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,int>> temp;

        for(int i = 0;i<heights.size();i++){
            temp.push_back({heights[i],i});
        }

        sort(temp.begin(),temp.end(),greater<pair<int,int>>());

        vector<string> ans;

        for(auto it : temp){
            ans.push_back(names[it.second]);
        }

        return ans;
    }
};