#include <bits/stdc++.h>
using namespace std;

void dfs (int node, unordered_map<int,list<int>> &adjList, 
    vector<int> &component, unordered_map<int,bool> &visited)
    {
        component.push_back(node);
        visited[node] = true;

        for (auto i:adjList[node]) {
            if (!visited[i]) {
                dfs(i,adjList,component,visited);
            }
        }
    }

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //creating an adjacency list
    unordered_map<int,list<int>> adjList;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    //travelling node one by one for all possible answers
    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            //storing answer for current node here
            vector<int> component;
            dfs(i,adjList,component,visited);
            ans.push_back(component);
        }
    }

    return ans;
}