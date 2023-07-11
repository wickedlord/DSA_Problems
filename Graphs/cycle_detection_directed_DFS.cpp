#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

bool isCycleDFS (int node, int parent, unordered_map<int,bool> &visited, 
unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &dfsVisited) {

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour:adjList[node]) {
        if (!visited[neighbour]) {
        bool cycleDetected = isCycleDFS(neighbour,node,visited,adjList,dfsVisited);
        if (cycleDetected) {
            return true;
        }
        }
        //visited to is case mai true hoga hi
        else if (dfsVisited[neighbour]) {
        return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//in this question, keep a track of dfsvisited and visited, dfsvisited will be
//reset after going back while visited not, check where these both are true

  unordered_map<int,list<int>> adjList;
    for (int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    //for disconnected graphs
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            //bool ans = isCycleBFS(i,visited,adjList);
            bool ans = isCycleDFS(i,-1,visited,adjList,dfsVisited);
            if (ans == 1) {
                return true;
            }
        }
    }
    return false;
}