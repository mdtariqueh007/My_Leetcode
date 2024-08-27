class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> prob(n,-1e9);
        prob[start] = 1.0;
        pq.push({1.0,start});
        while(!pq.empty()){
            int node = pq.top().second;
            double probability = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                double edP = it.second;

                if((edP*probability)>prob[adjNode]){
                    prob[adjNode] = edP*probability;
                    pq.push({prob[adjNode],adjNode});
                }

            }
        }

        if(prob[end]==-1e9) return 0;
        else return prob[end];

    }
};