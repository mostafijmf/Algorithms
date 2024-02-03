#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mv = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
bool vis[101][101];

int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
int cnt = 0;
void dfs(int k1, int k2, int q1, int q2)
{
    if (k1 == q1 && k2 == q2)
        return;
    vis[k1][k2] = true;
    for (int i = 0; i < 8; i++)
    {
        int new_i = k1 + mv[i].first;
        int new_j = k2 + mv[i].second;
        if (valid(new_i, new_j) && !vis[new_i][new_j])
        {
            cnt++;
            dfs(new_i, new_j, q1, q2);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        int board[n][m];
        memset(board, -1, sizeof(board));
        memset(vis, false, sizeof(vis));
        int k1, k2, q1, q2;
        cin >> k1 >> k2 >> q1 >> q2;
        // board[k1][k2] = 0;
        // board[q1][q2] = 1;
        cnt = 0;
        dfs(k1, k2, q1, q2);

        cout << cnt << endl;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}
