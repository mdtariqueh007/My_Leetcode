class Solution {
    
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;

        int n = s.length();

        vector<pair<int,long long>> adj[26];

        for(int i = 0;i<26;i++){
            int u = i;
            int v = (i+1)%26;

            adj[u].push_back({v,nextCost[u]});
            adj[v].push_back({u, previousCost[v]});

        }

        auto findCost = [&](int src, int tar) -> long long {
            if(src==tar) return 0;

            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
            vector<long long> dist(26,1e12);

            pq.push({0, src});
            dist[src] = 0;

            while(!pq.empty()){
                long long cost = pq.top().first;
                long long node = pq.top().second;

                pq.pop();

                for(auto it: adj[node]){
                    int adjNode = it.first;
                    long long edW = it.second;
                    
                    if(cost + edW<dist[adjNode]){
                        dist[adjNode] = cost + edW;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            } 

            return dist[tar];
        };

        for(int i = 0;i<n;i++){
            int src = s[i] - 'a';
            int tar = t[i] - 'a';

            ans += findCost(src, tar);
        }

        return ans;



    }
};