#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //preparing adjaceny list
    unordered_map <int, list<pair<int, int>>> adjList;
    for (int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adjList[u].push_back(make_pair(v,weight));
        adjList[v].push_back(make_pair(u,weight));
    }

    //creating the distance array
    vector<int> distance(vertices);
    for (int i=0; i<vertices; i++) {
        distance[i] = INT_MAX;
    }

    //creating a set, first is distance, second is node
    set<pair<int, int>> st;
    
    //setting the source node distance to be zero
    distance[source] = 0;

    //pushing the source node in stack
    st.insert(make_pair(0,source));

    //traversing set
    while (!st.empty()) {
        auto top = *(st.begin()); //finding the top of the set

        int nodeDistance = top.first;
        int node = top.second;

        //removing the node
        st.erase(st.begin());

        //traverse the neighbours
        for (auto neighbour:adjList[node]) {
            if (nodeDistance + neighbour.second < distance[neighbour.first]) {
                //delete if there exists an entry for it in the set
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                if (record != st.end()) {
                    st.erase(record);
                }

                //updating distance
                distance[neighbour.first] = nodeDistance + neighbour.second;

                //pushing the new record in set
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }

    return distance;
}
