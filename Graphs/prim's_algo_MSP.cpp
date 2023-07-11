#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map <int, list<pair<int,int>>> adj;
    //creating adjaceny list
    for (int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //creating the required arrays
    vector<int> distance(n+1); //for min distance between the nodes
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    //initialising the arrays
    for (int i=0; i<=n; i++) {
        distance[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    //start of logic
    distance[1] = 0;
    parent[1] = -1;

    for (int i=1; i<n; i++) {
        int mini = INT_MAX;
        int u;

        //search for the node with the least value in the distance array
        for (int v=1; v<=n; v++) {
            if (mst[v] == false && distance[v] < mini) {
                u = v;
                mini = distance[v];
            }
        }

        //mark the node as visited in mst
        mst[u] = true;

        //visit the neighbours of that node
        for (auto neighbour:adj[u]) {
            int v = neighbour.first;
            int w = neighbour.second;

            //check for condition
            if (mst[v] == false && w < distance[v]) {
                parent[v] = u;
                distance[v] = w;
            }
        }
    }

    //till now our distance array is ready
    //pushing the output in the result format
    vector<pair<pair<int, int>, int>> ans;
    for (int i=2; i<=n; i++) {
        ans.push_back({{parent[i], i}, distance[i]});
    }

    return ans;
}