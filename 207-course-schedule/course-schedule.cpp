class Solution {
    private:
    bool checkCycle(int node,vector<int> adj[],vector<int>&vis){
        vis[node] = 2;
        // dfsVis[node] = 1;

        for(auto it : adj[node]){
            if(vis[it]==0){
                if(checkCycle(it,adj,vis)){
                    return true;
                }
            }
            else if(vis[it]==2){
                return true;
            }
        }

        vis[node] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> adj[n];

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);


        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                if(checkCycle(i,adj,vis)){
                    return false;
                }
            }
        }

        return true;
    }
};