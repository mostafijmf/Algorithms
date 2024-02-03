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

int bfs(int k1, int k2, int q1, int q2)
{
    queue<pair<int, int>> q;
    q.push({k1, k2});
    vis[k1][k2] = true;
    int steps = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> par = q.front();
            q.pop();
            if (par.first == q1 && par.second == q2)
                return steps;
            for (int i = 0; i < 8; i++)
            {
                int new_i = par.first + mv[i].first;
                int new_j = par.second + mv[i].second;
                if (valid(new_i, new_j) && !vis[new_i][new_j])
                {
                    q.push({new_i, new_j});
                    vis[new_i][new_j] = true;
                }
            }
        }
        steps++;
    }
    return -1;
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
        board[k1][k2] = 0;
        board[q1][q2] = 1;
        int result = bfs(k1, k2, q1, q2);
        cout << result << endl;

        // cout << cnt << endl;

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
