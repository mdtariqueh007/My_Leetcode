class Solution {
    private:
    int bfs(vector<int> adj[],int n){
        vector<int> vis(n,0);

        queue<int> q;

        q.push(0);
        vis[0] = 1;

        int dis = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0;i<sz;i++){
                int node = q.front();
                q.pop();

                if(node==n-1){
                    return dis;
                }

                for(int it : adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
            dis++;
        }

        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;

        vector<int> adj[n];

        for(int i = 0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        for(auto q : queries){
            int u = q[0];
            int v = q[1];

            adj[u].push_back(v);

            ans.push_back(bfs(adj,n));
        }

        return ans;
    }
};