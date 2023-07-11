#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjl[N];
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjl.push_back(y);
        adjl.push_back(x);
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "->"
             << " ";
        vector<int>::iterator;

        for (int it = 0; it < y.size(); it++)
        {
            cout << y[it] << " ";
        }

        cout << endl;
    }
    return 0;
}
//***************************************************************************************
// bfs
#include "bits/stdc++.h"
using namespace std;
int main()
{
    int N = 1e5 + 2;
    vector<int> adj[N];
    bool vis[N];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i++)
    {
        vis[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (vis[*it] == false)
            {
                q.push(*it);
                vis[*it] = true;
            }
        }
    }
    return 0;
}
//*****************************************************************************
// dfs
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2;
vector<int> adj[N];
bool vis[N];

void dfs(int node)
{
    vis[node] = true;
    // preorder
    // cout<<node<<endl;
    vector<int>::iterator it;
    // inorder
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
        {

            dfs(*it);
        }
    }
    // postorder
    cout << node << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i++)
    {
        vis[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    return 0;
}