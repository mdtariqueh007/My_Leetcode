class Solution {
    private:
    bool findBobPath(int node, int time, vector<int> adj[], vector<bool>&visited, unordered_map<int,int>&bobPath){
        bobPath[node] = time;
        visited[node] = true;

        if(node==0){
            return true;
        }

        for(auto adjNode: adj[node]){
            if(!visited[adjNode]){
                if(findBobPath(adjNode, time + 1, adj, visited, bobPath)){
                    return true;
                }
            }
        }

        bobPath.erase(node);
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int m = edges.size();

        int n = m + 1;

        vector<int> adj[n];

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_map<int,int> bobPath;
        vector<bool> visited(n, false);

        findBobPath(bob, 0, adj, visited, bobPath);

        visited.assign(n, false);

        queue<vector<int>> q;
        q.push({0, 0, 0}); //node, time, income

        int maxIncome = -1e9;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it[0];
            int time = it[1];
            int income = it[2];

            if(bobPath.find(node)==bobPath.end() || time<bobPath[node]){
                income += amount[node];
            }
            else if(time==bobPath[node]){
                income += (amount[node]/2);
            }

            if(adj[node].size()==1 && node!=0){
                maxIncome = max(maxIncome, income);
            }

            for(auto adjNode: adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = true;
                    q.push({adjNode, time+1, income});
                }
            }
        }

        return maxIncome;
    }
};