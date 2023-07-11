#include <bits/stdc++.h> 
using namespace std;

void topoSort(unordered_map<int,list<int>> &adj, queue<int> &q, 
vector<int> &indegree, vector<int> &ans) {
    
    while (!q.empty()) {
        int front = q.front();
        ans.push_back(front);
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

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //approach 2: Kahn's Algorithm
    unordered_map<int,list<int>> adj;
    for (int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //calculating indegree
    vector<int> indegree(v,0);
    for (auto i:adj) {
        for (auto j:i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    //those having 0 indegree are pushed back
    for (int i=0; i<v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    topoSort(adj, q, indegree, ans);
    return ans;
}