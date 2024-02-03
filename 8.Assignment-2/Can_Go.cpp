#include <bits/stdc++.h>
#define ll long long int
using namespace std;
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
                adj[i][j] = 1e18;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
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

    int src, tc;
    cin >> src >> tc;
    while (tc--)
    {
        int d, w;
        cin >> d >> w;

        // if (src == d && adj[src][d] != w)
        // {
        //     cout << "NO" << endl;
        //     continue;
        // }
        // else 
        if (adj[src][d] <= w)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if(adj[i][j] == 1e9) cout << "F" << " ";
    //         else cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    /*
    0 3 2 4 5 
    F 0 F 7 2 
    F 1 0 2 3 
    F F F 0 5 
    F F F F 0
    */

    return 0;
}
