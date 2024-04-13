class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<pair<int,int>> adj[n];


        for(auto it : edges){
            if(it[0]==it[1]) continue;
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	    vector<int> dist(n,INT_MAX);

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(dis>dist[node]){
                continue;
            }

            if(dis>=disappear[node]){
                continue;
            }

            for(auto it : adj[node]){
                if(dis + it.second<dist[it.first] && dis+it.second<disappear[it.first]){
                    dist[it.first] = dis + it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }

        return dist;
        
    }
};