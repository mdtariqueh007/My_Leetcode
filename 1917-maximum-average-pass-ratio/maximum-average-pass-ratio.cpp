class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateGain = [](int passStudents, int totalStudents){
            return (double)(passStudents + 1)/(double)(totalStudents + 1) - 
                    (double)(passStudents)/(double)(totalStudents);
        };

        priority_queue<pair<double, pair<int,int>>> pq;

        for(auto c: classes){
            pq.push({calculateGain(c[0], c[1]),{c[0], c[1]}});
        }

        while(extraStudents--){
            auto it = pq.top();

            pq.pop();

            int passStudents = it.second.first;
            int totalStudents = it.second.second;

            pq.push({calculateGain(passStudents + 1, totalStudents + 1),{passStudents + 1, totalStudents + 1}});
        }

        double totalPassRatio = 0.0;

        while(!pq.empty()){
            auto it = pq.top();

            pq.pop();

            int passStudents = it.second.first;
            int totalStudents = it.second.second;

            totalPassRatio += (passStudents * 1.0)/(totalStudents * 1.0);
        }

        return totalPassRatio/classes.size();
    }
};