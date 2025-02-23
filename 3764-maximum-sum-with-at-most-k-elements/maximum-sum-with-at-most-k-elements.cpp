class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {

        vector<int> allowed;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            sort(grid[i].rbegin(),grid[i].rend());
            int j = 0;
            while(j<m && j+1<=limits[i]){
                allowed.push_back(grid[i][j]);
                j++;
            }
        }

        sort(allowed.rbegin(), allowed.rend());

        long long ans = accumulate(allowed.begin(), allowed.begin()+k, 0LL);

        return ans;

        
    }
};