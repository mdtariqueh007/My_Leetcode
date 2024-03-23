#include "bits/stdc++.h"

void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int> &st){
	vis[node] = 1;

	for(auto it : adj[node]){
		if(!vis[it]){
			dfs(it,adj,vis,st);
		}
	}

	st.push(node);
}

void dfs3(int node,vector<int>&vis,vector<int> adj[]){
	vis[node] = 1;

	for(auto it : adj[node]){
		if(!vis[it]){
			dfs3(it,vis,adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	vector<int> adj[v];

	for(auto edge : edges){
		adj[edge[0]].push_back(edge[1]);
	}

	stack<int> st;

	vector<int> vis(v,0);

	for(int i = 0;i<v;i++){
		if(!vis[i]){
			dfs(i,adj,vis,st);
		}
	}

	vector<int> adjT[v];

	for(int i = 0;i<v;i++){
		vis[i] = 0;
		for(auto it : adj[i]){
			adjT[it].push_back(i);
		}
	}

	int scc = 0;

	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(!vis[node]){
			dfs3(node,vis,adjT);
			scc++;
		}
	}

	return scc;
}
