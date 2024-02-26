#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
vector<int> adj[N];
bool vis[N];
int par[N];
int cntEdges = 0;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : adj[parent])
        {
            if (!vis[child])
            {
                vis[child] = true;
                par[child] = parent;
                q.push(child);
            }
            else if (par[parent] != child)
            {
                cntEdges++;
            }
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
    memset(par, -1, sizeof(par));
    bfs(1);
    cout << cntEdges;

    return 0;
}
