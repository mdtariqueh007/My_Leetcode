class Solution {
public:
    // static bool cmp(vector<int> a,vector<int> b){
    //     return b[1]>a[1];
    // }
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(),points.end());
        int end = points[0][1];
        int arrow = 1;

        for(auto point : points){
            if(point[0]>end){
                arrow++;
                end = point[1];
            }
            end = min(point[1],end);
        }

        return arrow;
        
    }
};