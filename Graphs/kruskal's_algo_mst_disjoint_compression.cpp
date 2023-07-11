#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool cmp (vector<int> &a, vector<int> &b) {
  return a[2] < b[2];
}

void makeSet (vector<int> &parent, vector<int> &rank, int n) {
  for (int i=0; i<n; i++) {
    parent[i] = i; //make parent of all the elements to themselves
    rank[i] = 0; //rank of all of them is 0, i.e., no other element is connected to them
  }
}

int findParent (vector<int> &parent, int node) {
  if (parent[node] == node) { //i.e. we have reached the top of a tree
    return node;
  }

  return parent[node] = findParent(parent, parent[node]);
  //changed the parent so that we won't have to traverse the whole tree again
  //also called the compression algo
}

void unionSet (int u, int v, vector<int> &parent, vector<int> &rank) {
  u = findParent(parent, u);
  v = findParent(parent, v);

  if (rank[u] < rank[v]) {
    parent[u] = v;
  }
  
  else if (rank[u] > rank[v]) {
    parent[v] = u;
  }
  
  else {
    parent[v] = u;
    rank[u]++;
  }
  
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  //based on disjoint sets, compression algorithms, kruskal's algo

  //sorting the elements based on their weights
  sort(edges.begin(), edges.end(), cmp);
  vector<int> parent(n); 
  vector<int> rank(n);

  makeSet(parent, rank, n); //intialize the disjoint sets

  int totalWeight = 0;
  //complete the sets
  for (int i=0; i<edges.size(); i++) {
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int weight = edges[i][2];

    if (u != v) { //means the elements have their parents not the same
      totalWeight += weight; //we have to add them in MST
      unionSet(u, v, parent, rank);
    }
  }

  return totalWeight;
}