#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2;
vector<vector<int>> g[N];
vector<int> dist(N);

const int INF = 1e9;
void djiktra(int src, int n)
{
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[src] = 0;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *s.begin();
        s.erase(x);

        for (auto it : g[x[1]])
        {

            if (dist[it[0]] > it[1] + dist[x[1]])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1] + dist[x[1]];
                s.insert({dist[it[0]], it[0]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < INF)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int src;
    cin >> src;
    djiktra(src, n);

    return 0;
}