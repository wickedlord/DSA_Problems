#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//logic is in bfs travel, we always reach the destination first using shortest path
	//step 1: prepare adjacency list
	unordered_map<int,list<int>> adj;
    for (int i=0; i<m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	
	//step 2: traverse bfs, save parent as well
	unordered_map<int,bool> visited;
	visited[s] = true;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);
	parent[s] = -1;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (auto neighbour:adj[front]) {
			if (!visited[neighbour]) {
				q.push(neighbour);
				visited[neighbour] = true;
				parent[neighbour] = front;
			}
		}
	}

	//step 3: backtrack parent array till reach source node
	vector<int> ans;
	int currentNode = t;
	ans.push_back(currentNode);
	while (currentNode != s) {
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	//step 4: reverse the array
	reverse(ans.begin(), ans.end());

	return ans;
}
