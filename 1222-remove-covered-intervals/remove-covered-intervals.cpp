class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [&](vector<int>&a, vector<int>&b){
            if(a[0]!=b[0]){
                return a[0]<b[0];
            }
            return a[1]>b[1];
        });

        int prevEnd = intervals[0][1];

        int cnt = 1;

        for(int i = 1;i<intervals.size();i++){
            if(prevEnd>=intervals[i][1]){
                continue;
            }

            prevEnd = intervals[i][1];
            cnt++;
        }

        return cnt;
        
    }
};