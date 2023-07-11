#include <bits/stdc++.h>
using namespace std;

void dfs (int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
           vector<vector<int>> &result, unordered_map<int,list<int>> &adj, 
           unordered_map<int,bool> &visited) {

               visited[node] = true;
               disc[node] = low[node] = timer++;

               for (auto nbr:adj[node]) {
                   if (nbr == parent) { //means we are going back from where we were
                       continue;
                   }

                   if (!visited[nbr]) {
                       dfs(nbr,node,timer,disc,low,result,adj,visited);
                       low[node] = min(low[node],low[nbr]);
                       //check if edge is bridge
                       if (low[nbr] > disc[node]) {//means nbr has never been visited before by any other node
                            vector<int> ans;
                            ans.push_back(node);
                            ans.push_back(nbr);
                            result.push_back(ans);
                       }
                   }
               

                    else {//the edge is not visited and is is therefore a backedge
                        low[node] = min(low[node],disc[nbr]);
                    }
               }
           }


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //prepare adjacency list
    unordered_map <int, list<int>> adj;
    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //create all the requird ds
    vector<int> disc(v); //discovery time
    vector<int> low(v); //lowest time to discover a node
    int parent = -1; //parent of the current node
    int timer = 0; 
    unordered_map<int, bool> visited;

    vector<vector<int>> result;

    for (int i=0; i<v; i++) { //initialise all the times
        disc[i] = -1; 
        low[i] = -1;
    }

    //travel dfs for each node
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs(i,parent,timer,disc,low,result,adj,visited);
        }
    }

    return result;
}