#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

bool isCycleDFS (int node, int parent, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adjList) {
    visited[node] = true;

    for (auto neighbour:adjList[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = isCycleDFS(neighbour,node,visited,adjList);
            if (cycleDetected) {
                return true;
            }
        }
        else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adjList;
    for (int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    //for disconnected graphs
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            //bool ans = isCycleBFS(i,visited,adjList);
            bool ans = isCycleDFS(i,-1,visited,adjList);
            if (ans == 1) {
                return "Yes";
            }
        }
    }
    return "No";
}
