#include <bits/stdc++.h>
using namespace std;

class graph {
    public:
        unordered_map<int, list<pair<int,int>>> adjList;

        void addEdge(int u, int v, int weight) {
            pair<int,int> p = make_pair(v,weight);
            adjList[u].push_back(p);
        }

        void printAdj () {
            for (auto i:adjList) {
                cout << i.first << " -> ";
                for (auto j:i.second) {
                    cout << "(" << j.first << " , " << j.second << "), ";
                }
                cout << endl;
            }
        }

        void dfs(int node, unordered_map<int,bool> &visited, stack<int> &s) {
            visited[node] = true;
            for (auto neighbour:adjList[node]) {
                if (!visited[neighbour.first]) {
                    dfs(neighbour.first, visited, s);
                }
            }
            s.push(node);
        }

        void getShortestPath (int src, vector<int> &distance, stack<int> &topo) {
            distance[src] = 0; //khud ka khud se distance always 0

            while (!topo.empty()) {
                int top = topo.top();
                topo.pop();

                //if possible if na ho vaha tk jaana
                if (distance[top] != INT_MAX) {
                    for (auto i:adjList[top]) {
                        //current element tk ka distance + weight of the edge to the other
                        if (distance[top] + i.second < distance[i.first]) {
                            distance[i.first] = distance[top] + i.second;
                        }
                    }
                }
            }
        }
};

int main () {
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n = 6; //number of nodes
    //topological sorting first
    unordered_map<int,bool> visited;
    stack<int> s;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            g.dfs(i,visited,s);
        }
    }

    //src node is 1
    int src = 1;
    //a distance array is created to note the distance of 1 to all other nodes
    vector<int> distance(n);
    for (int i=0; i<n; i++) {
        distance[i] = INT_MAX; //initialised it to the max dist possible
    }

    g.getShortestPath(src, distance, s);

    cout << "Printing answer : " << endl;
    for (int i=0; i<n; i++) {
        cout << distance[i] << " ";
    }

    cout << endl;
}