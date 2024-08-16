class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int m = arrays.size();

        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();

        int maxDis = 0;

        for(int i = 1;i<m;i++){
            maxDis = max(maxDis, max(maxVal - arrays[i][0],arrays[i].back() - minVal));

            maxVal = max(maxVal,arrays[i].back());
            minVal = min(minVal,arrays[i][0]);
        }

        return maxDis;
        
    }
};