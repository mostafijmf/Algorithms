#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
bool pathVis[N];
vector<int> adj[N];
bool ans = false;

void dfs(int par)
{
    vis[par] = true;
    pathVis[par] = true;
    for (int child : adj[par])
    {
        if (pathVis[child])
            ans = true;
        if (!vis[child])
        {
            dfs(child);
        }
    }
    pathVis[par] = false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    if (ans)
        cout << "Cycle found";
    else
        cout << "Cycle not found";

    return 0;
}
