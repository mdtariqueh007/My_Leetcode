class Solution {
    private:
    vector<vector<int>> mergeIntervals(vector<vector<int>>&intervals){
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            if(ans.size()==0 || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }

        return ans;
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> mergedMeetings = mergeIntervals(meetings);

        
        int busyDays = 0;

        for(auto it  : mergedMeetings){
            busyDays += (it[1] - it[0]+1);
        }

        return days - busyDays;
    }
};