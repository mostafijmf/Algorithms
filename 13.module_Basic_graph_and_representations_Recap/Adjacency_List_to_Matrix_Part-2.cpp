#include <bits/stdc++.h>
using namespace std;

void convert(vector<pair<int, int>> adj[], int n)
{
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = -1;
            if (i == j)
                mat[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> v : adj[i])
        {
            mat[i][v.first] = v.second;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    convert(adj, n);
    // for (auto val : adj[3])
    //     cout << val.first << " " << val.second << endl;

    return 0;
}
