class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;
        for(int i = 0;i<timePoints.size();i++){
            string time = timePoints[i];
            
            int h = stoi(time.substr(0,2));
            int m = stoi(time.substr(3));

            int min = h * 60 + m;

            minutes.push_back(min);
        }

        sort(minutes.begin(),minutes.end());

        int ans = 1e9;

        for(int i = 1;i<minutes.size();i++){
            ans = min(ans,minutes[i] - minutes[i-1]);
        }

        ans = min(ans,minutes[0] - minutes.back() + 24 * 60);

        return ans;
        
    }
};