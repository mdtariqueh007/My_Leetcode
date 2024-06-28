class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);

        for(auto it : roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }

        sort(degree.begin(),degree.end());

        long long val = 1;
        long long sum = 0;
        for(long long d  : degree){
            sum += (d * val);
            val++;
        }

        return sum;


    }
};