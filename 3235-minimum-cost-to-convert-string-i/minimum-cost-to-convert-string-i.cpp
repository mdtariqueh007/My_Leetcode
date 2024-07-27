class Solution {
    private:
    vector<long long> helper(int src,vector<pair<int,int>> adj[]){

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        vector<long long> dist(26,1e9);

        pq.push({0,src});

        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;

            pq.pop();

            for(auto it :  adj[node]){
                int adjNode = it.first;
                int w = it.second;

                if(dist[adjNode]>d + w){
                    dist[adjNode] = d + w;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }


        return dist;



    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        vector<pair<int,int>> adj[26];

        for(int i = 0;i<n;i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }

        vector<vector<long long>> dist(26,vector<long long>(26));

        for(int i = 0;i<26;i++){
            dist[i] = helper(i,adj);
        }

        long long ans = 0;

        for(int i = 0;i<source.length();i++){
            if(source[i]!=target[i]){
                int cnt = dist[source[i]-'a'][target[i]-'a'];

                if(cnt==1e9){
                    return -1;
                }

                ans += cnt;
            }
        }

        return ans;



    }
};