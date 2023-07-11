#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2;
vector<int> parent(N);
vector<int> sz(N);
void makeset(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int findset(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = findset(parent[x]);
}
void unionsets(int a, int b)
{
    int x = findset(a);
    int y = findset(b);
    if (x != y)
    {
        if (sz[x] < sz[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        makeset(i);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj.push_back({w, x, y});
    }
    sort(adj.begin(), adj.end());
    int cost = 0;
    for (auto i : adj)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int a = findset(u);
        int b = findset(v);
        if (a == b)
        {
            continue;
        }
        else
        {
            cout << u << " " << v << endl;
            cost += w;
            unionsets(u, v);
        }
    }
    cout << cost << endl;
    return 0;
}
//***************************************************************
// prims
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2;
vector<vector<int>> g[N];
vector<int> dist(N);
vector<int> vis(N);
vector<int> parent(N);
int cost = 0;
const int INF = 1e9;
void prims(int src)
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
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        vis[x[1]] = 1;
        cout << u << " " << v << " " << w << endl;
        cost += w;
        for (auto it : g[x[1]])
        {
            if (vis[it[0]])
            {
                continue;
            }
            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
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
    prims(0);
    cout << cost << endl;
    return 0;
}