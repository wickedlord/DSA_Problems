#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

bool isCycleBFS(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adjList) {
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front]) {
            //condition for cycle to exist
            if ((visited[neighbour] == true) && (neighbour != parent[front])) {
                return true;
            }
            else if (!visited[neighbour]) {
                parent[neighbour] = front;
                visited[neighbour] = true;
                q.push(neighbour);
            }
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
            bool ans = isCycleBFS(i,visited,adjList);
            if (ans == 1) {
                return "Yes";
            }
        }
    }
    return "No";
}
