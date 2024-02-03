#include <bits/stdc++.h>
using namespace std;

vector<int> v[1000];
bool vis[1000];
int dist[1000];

void bfs(int src, int des)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dist[child] = dist[par] + 1;

                if (child == des)
                {
                    cout << dist[child] << endl;
                    return;
                }
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        memset(vis, false, sizeof(vis));
        bfs(s, d);
    }

    return 0;
}
