class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<int> degree(n+1,0);

        for(auto it  :edges){
            degree[it[0]]++;
            degree[it[1]]++;
        }

        for(int i = 1;i<=n;i++)
        {
            if(degree[i]>1){
                return i;
            }
        }

        return -1;

    }
};