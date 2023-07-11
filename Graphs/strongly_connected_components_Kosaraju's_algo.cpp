#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &s) {
	visited[node] = true;
	for (auto nbr:adj[node]) {
		if (!visited[nbr]) {
			dfs(nbr,adj,visited,s);
		}
	}

	s.push(node); //topo logic
}

void revDFS(int node, unordered_map <int, list<int>> &adj, unordered_map<int, bool> &visited) {
	visited[node] = true;
	for (auto nbr:adj[node]) {
		if (!visited[nbr]) {
			revDFS(nbr, adj, visited);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map <int, list<int>> adj;
	for (int i=0; i<edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	//topological order prepration
	unordered_map<int, bool> visited;
	stack<int> s;
	for (int i=0; i<v; i++) {
		if (!visited[i]) {
			dfs(i,adj,visited,s);
		}
	}

	//now tranpose the graph
	unordered_map<int,list<int>> tranpose;
	for (int i=0; i<v; i++) {
		visited[i] = 0;
		for (auto nbr:adj[i]) {
			tranpose[nbr].push_back(i); //reverses the edge
		}
	}

	//dfs calls based on the above preparation
	int count = 0;
	while (!s.empty()) {
		int top = s.top();
		s.pop();
		if (!visited[top]) {
			count++; //to check number of SCC
			revDFS(top, tranpose, visited);
		}
	}

	return count++;
}