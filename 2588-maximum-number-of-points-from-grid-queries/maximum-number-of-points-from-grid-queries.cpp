class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

        vector<pair<int,int>> sortedQueries;

        for(int i = 0;i<queries.size();i++){
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(queries.size(), 0);

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int cnt = 0;

        for(auto q: sortedQueries){
            int qVal = q.first;
            int qInd = q.second;
            

            while(!pq.empty() && pq.top().first<qVal){
                int row = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();

                cnt++;

                for(int k = 0;k<4;k++){
                    int nrow = row + dx[k];
                    int ncol = col + dy[k];

                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol]){
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                        vis[nrow][ncol] = 1;
                    }
                }
            }

            ans[qInd] = cnt;
        }

        return ans;
        


        
    }
};