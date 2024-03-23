#include "bits/stdc++.h"

int timer = 0;

void dfs(int node,int parent,vector<int> adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;

    timer++;

    for(auto it  : adj[node]){
        if(it==parent) continue;
        if(vis[it]==0){
            dfs(it,node,adj,vis,tin,low,bridges);
            low[node] = min(low[node],low[it]);

            if(low[it] > tin[node]){
                bridges.push_back({it,node});
            }
        }else{
            low[node] = min(low[node],low[it]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here

    vector<int> adj[v];

    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(v,0),tin(v,0),low(v,0);
    vector<vector<int>> bridges;
    dfs(0,-1,adj,vis,tin,low,bridges);

    return bridges;


}
