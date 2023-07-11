#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

void topoSort(unordered_map<int,list<int>> &adj, queue<int> &q, 
vector<int> &indegree, int &ans) {
  
  while (!q.empty()) {
    int front = q.front();
    ans++;
    q.pop();

    //find neighbours and reduce their indegree as the element to which they
    //were connected has already been processed
    for (auto neighbour:adj[front]) {
      indegree[neighbour]--;
      //again check for indegrees after updating
      if (indegree[neighbour] == 0) {
        q.push(neighbour);
      }
    }
  }
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //approach 2:using Kahn's Algorithm, only applied on directed acyclic graph
  //wrong topo sort will say cycle is present
  unordered_map<int,list<int>> adj;
  for (int i=0; i<edges.size(); i++) {
    int u = edges[i].first-1;
    int v = edges[i].second-1;

    adj[u].push_back(v);
  }

  //calculating indegree
  vector<int> indegree(n,0);
  for (auto i:adj) {
    for (auto j:i.second) {
      indegree[j]++;
    }
  }

  queue<int> q;
  int count = 0;

  //those having 0 indegree are pushed back
  for (int i=0; i<n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  topoSort(adj, q, indegree, count);
  //if count == number of elements, it means we have a correct topo order
  if (count == n) {
    return false;
  }
  else return true;
}