#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const ll N = 1e18;
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    ll s;
    cin >> s;

    ll dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            dis[s] = 0;
        else
            dis[i] = N;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u = ed.u;
            ll v = ed.v;
            ll c = ed.c;
            if (dis[u] < N && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        ll u = ed.u;
        ll v = ed.v;
        ll c = ed.c;
        if (dis[u] < N && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        ll tc;
        cin >> tc;
        while (tc--)
        {
            ll d;
            cin >> d;

            if (dis[d] == N)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;

// const ll N = 1e18;

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     ll adj[n + 1][n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j)
//                 adj[i][j] = 0;
//             else
//                 adj[i][j] = N;
//         }
//     }
//     ll maxCost = 0;
//     while (e--)
//     {
//         ll a, b, c;
//         cin >> a >> b >> c;
//         adj[a][b] = c;
//         if (maxCost < c)
//             maxCost = c;
//     }

//     for (int k = 1; k <= n; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (adj[i][k] + adj[k][j] < adj[i][j])
//                 {
//                     adj[i][j] = adj[i][k] + adj[k][j];
//                 }
//             }
//         }
//     }

//     bool isCycle = false;
//     for (int i = 1; i <= n; i++)
//     {
//         if (adj[i][i] < 0)
//         {
//             isCycle = true;
//             break;
//         }
//     }

//     int src, tc;
//     cin >> src >> tc;

//     if (isCycle)
//         cout << "Negative Cycle Detected";
//     else
//     {
//         while (tc--)
//         {
//             int d;
//             cin >> d;
//             if (adj[src][d] > maxCost)
//                 cout << "Not Possible" << endl;
//             else
//                 cout << adj[src][d] << endl;
//         }
//     }

//     // for (int i = 1; i <= n; i++)
//     // {
//     //     for (int j = 1; j <= n; j++)
//     //     {
//     //         if(adj[i][j] == 1e5) cout << "F" << " ";
//     //         else cout << adj[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     return 0;
// }
