class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<int> adj[n];

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            u--;
            v--;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist1(n,1e9), dist2(n,1e9), vis(n,0);

        dist1[0] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;

            pq.pop();

            vis[node]++;

            if(vis[node]==2 && node==n-1){
                return d;
            }

            if((d/change)%2){
                
                d = (d/change+1)*change + time;
            }
            else{

                d = d + time;
                
            }

            

            for(int v : adj[node]){
                if(vis[v]==2) continue;
                if(dist1[v]>d){
                    dist2[v] = dist1[v];
                    dist1[v] = d;
                    pq.push({d,v});
                }
                else if(dist2[v]>d && d!=dist1[v]){
                    dist2[v] = d;
                    pq.push({d,v});
                }
            }




        }


        return 0;
        
    }
};