#include <bits/stdc++.h>
using namespace std;
//working fine in online compiler, vs code issue
void dfs(int node, int parent, vector<int> &disc, vector<int>&low, int &timer,vector<int> &ap, unordered_map<int, bool> &visited, unordered_map<int,list<int>> &adj) {

    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    //start traversing the neighbours
    for (auto nbr:adj[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!visited[nbr]) {
            dfs(nbr,node,disc,low,timer,ap,visited,adj);
            //after coming back check if it's neighbour has it's low updated, so that
            //the current node can as well
            low[node] = min(low[node], low[nbr]);
            //check the condition for AP
            if ((low[nbr] >= disc[node]) && (parent != -1)) {
                ap[node] = 1;
            }
            child++;
        }

        else {
            //means we have come to a neighbour that has already been visited
            low[node] = min(low[node], disc[nbr]);
        }
    }

    //a different case for starting node
    if (parent == -1 && child > 1) {
        ap[node] = 1;
    }
}

int main () {
    int n = 5; //number of nodes
    int e = 5; //number of edges

    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    //prepare adjacency list
    unordered_map<int, list<int>> adj;
    for (int i=0; i<e; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //preparing the required ds
    vector<int> disc(n);
    vector<int> low(n);
    vector<int> ap(n,0); //articulation points, initialized by 0
    int timer = 0;
    unordered_map<int, bool> visited;

    //calling dfs function
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i,-1,disc,low,timer,ap,visited,adj);
        }
    }

    //printing the articulation points list
    cout << "Printing the AP points list : " << endl;
    for (int i=0; i<n; i++) {
        if (ap[i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}