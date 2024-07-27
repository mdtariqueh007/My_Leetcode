class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        

        vector<vector<long long>> dist(26,vector<long long>(26,INT_MAX));

        for(int i = 0;i<original.size();i++){
            int src = original[i]-'a';
            int dest = changed[i]-'a';
            long long wt = cost[i]*1LL;

            dist[src][dest] = min(dist[src][dest],wt);
        }

        for(int k = 0;k<26;k++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        long long ans = 0;

        for(int i = 0;i<source.size();i++){
            if(source[i]!=target[i]){
                long long cnt = dist[source[i]-'a'][target[i]-'a'];

                if(cnt>=INT_MAX){
                    return -1;
                }

                ans += cnt;
            }
        }

        return ans;






    }
};