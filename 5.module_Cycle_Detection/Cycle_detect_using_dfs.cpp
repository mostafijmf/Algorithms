#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
int parVis[N];
vector<int> adj[N];
bool ans = false;
void dfs(int par)
{
    vis[par] = true;
    for (int child : adj[par])
    {
        if (vis[child] && parVis[par] != child)
        {
            ans = true;
        }

        if (!vis[child])
        {
            parVis[child] = par;
            dfs(child);
        }
    }
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
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parVis, -1, sizeof(parVis));
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
