class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> line(101,0);

        for(vector<int> log: logs){
            line[log[0] - 1950]++;
            line[log[1] - 1950]--;
        }

        int cnt = 0;
        int maxPop = 0;
        int ansYear;

        for(int i = 0;i<101;i++){
            cnt += line[i];

            if(cnt>maxPop){
                maxPop = cnt;
                ansYear = i + 1950;
            }
        }

        return ansYear;
    }
};