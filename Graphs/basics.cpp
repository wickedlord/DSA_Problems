#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph {
    public:
        unordered_map<T,list<T>> adj;

        void addEdge (int u, int v, bool directed) {
            //push in given direction
            adj[u].push_back(v);
            //directed = 0, means undirected graph, so pushing both sides
            if (directed == false) {
                adj[v].push_back(u);
            }
        }

        void printAdj () {
            for (auto i:adj) {
                cout << i.first << " -> ";
                for (auto j:i.second) {
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

int main () {
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    graph<int> g;

    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    g.printAdj();
}

