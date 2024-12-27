class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int n = values.size();

        int maxValueTillNow = values[0] + 0;

        int ans = 0;

        for(int i = 1;i<n;i++){
            ans = max(ans, maxValueTillNow + values[i] - i);

            maxValueTillNow = max(maxValueTillNow, values[i] + i);
        }

        return ans;
        
    }
};