#include <bits/stdc++.h>
using namespace std;
 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    //bellman ford is used to find the min distance when the weight of the 
    //edges might contain negative integers.

    //dijkstra's algo doesn't have this feature
    //bellman ford can be used on both directed and undirected graphs

    //we need to check the condn n-1 times, on the nth time if there is no change
    //in the distance, that means that there is no -ve cycle present

    vector<int> distance(n+1, 1e9); //initialized 
    distance[src] = 0;

    //looping n-1 times
    for (int i=1; i<n; i++) {
        for (int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (distance[u] != 1e9 && distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }

    //further code is required only for checking -ve cycle
    bool flag = 0;
    for (int j=0; j<m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (distance[u] != 1e9 && distance[u] + wt < distance[v]) {
           flag = 1;
        }
    }

    if (flag == 1) {
        return -1;
    }

    return distance[dest];
    
}