#include <bits/stdc++.h> 
using namespace std;

void prepareList (unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges) {
    //using sets instead of list as sets store element in order
    for (int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs (unordered_map<int, set<int>> &adjList, vector<int> &ans, unordered_map<int,bool> &visited, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        //traversing all the connected vertices of the node
        for (auto i:adjList[frontNode]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    //preparing adjacency matrix
    prepareList(adjList,edges);
    
    //travelling for each node
    for (int i=0; i<vertex; i++) {
        if (!visited[i]) {
            bfs(adjList,ans,visited,i);
        }
    }

    return ans;
}