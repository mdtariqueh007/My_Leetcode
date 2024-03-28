class Solution {
    private:
    #define int long long
    void dfs(int node,vector<int>adj[],vector<int>&vis,int&cnt){
        vis[node] = 1;
        cnt++;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,cnt);
            }
        }
    }
    #undef int
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        #define int long long

        int n = bombs.size();
        vector<int> adj[n];

        for(int i = 0;i<n;i++){
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];

            for(int j = 0;j<n;j++){
                if(i==j) continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                int x = abs(x1-x2);
                int y = abs(y1-y2);

                if((x*x+y*y<=r1*r1) ){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                }
            }
        }

        int maxi = 0;

        for(int i = 0;i<n;i++){
            vector<int> vis(n,0);
            int c = 0;
            dfs(i,adj,vis,c);
            maxi = max(maxi,c);
        }

        #undef int

        return maxi;

        
        
    }
};