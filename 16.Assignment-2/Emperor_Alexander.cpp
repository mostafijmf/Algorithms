#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Edge
{
public:
    int u, v;
    ll w;
    Edge(int u, int v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
const int N = 1e5 + 5;
int par[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    bool vis[n];
    for (int i = 1; i <= n; i++)
        vis[i] = false;

    vector<Edge> edgeList;
    while (e--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
        vis[u] = true;
        vis[v] = true;
    }

    bool ans = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ans = false;

    if (ans)
    {
        sort(edgeList.begin(), edgeList.end(), cmp);
        ll totalCost = 0;
        int removeRoad = 0;
        for (Edge ed : edgeList)
        {
            int leaderU = dsu_find(ed.u);
            int leaderV = dsu_find(ed.v);
            if (leaderU == leaderV)
            {
                removeRoad++;
                continue;
            }
            else
            {
                dsu_union_by_size(ed.u, ed.v);
                totalCost += ed.w;
            }
        }
        cout << removeRoad << " "<< totalCost;
    }
    else
        cout << "Not Possible";

    return 0;
}
