class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {

        int last = 0;

        int maxi = 0;
        int empId = n;

        for(auto it : logs){
            int id = it[0];
            int endTime = it[1];

            int timeWorked = endTime - last;
            if(timeWorked>=maxi){
                
                empId = (maxi==timeWorked)?min(id,empId):id;
                maxi = timeWorked;
            }
            last = endTime;
        }

        return empId;
        
    }
};