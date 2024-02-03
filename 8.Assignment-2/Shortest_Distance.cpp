#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e18;
int main()
{
    int n, e;
    cin >> n >> e;
    ll adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = N;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] > c)
            adj[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--)
    {
        int s, d;
        cin >> s >> d;

        if (adj[s][d] == N)
            cout << -1 << endl;
        else
            cout << adj[s][d] << endl;
    }

    return 0;
}
