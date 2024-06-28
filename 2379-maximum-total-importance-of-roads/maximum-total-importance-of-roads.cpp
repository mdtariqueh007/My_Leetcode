class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> degree(n);

        for(int i = 0;i<n;i++){
            degree[i].second = i;
        }

        for(auto it  : roads){
            degree[it[0]].first++;
            degree[it[1]].first++;
        }


        sort(degree.rbegin(),degree.rend());

        int rank = n;

        vector<int> val(n);

        for(int i = 0;i<n;i++){
            val[degree[i].second] = rank--;
        }

        long long sum  = 0;

        for(auto it : roads){
            sum += (val[it[0]] + val[it[1]]);
        }

        return sum;
        
    }
};