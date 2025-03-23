class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        vector<long long> time(n,LONG_MAX);
        vector<long long> ways(n,0);
        time[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            long long t = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                long long adjNode = it.first;
                long long edW = it.second;
                if(t+edW<time[adjNode]){
                    time[adjNode] = (t+edW);
                    ways[adjNode] = ways[node]%mod;
                    pq.push({time[adjNode],adjNode});
                }
                else if(t+edW==time[adjNode]){
                   
                   ways[adjNode] = ((ways[adjNode]%mod+ways[node])%mod)%mod;

                }
             }
        }

        return ways[n-1]%mod;

    }
};