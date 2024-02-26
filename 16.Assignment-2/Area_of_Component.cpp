#include <bits/stdc++.h>
using namespace std;

bool vis[1005][1005];
char mat[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 1 || i >= n + 1 || j < 1 || j >= m + 1)
        return false;
    else if (mat[i][j] == '-')
        return false;
    return true;
}
int cnt = 0;
void bfs(int si, int sj)
{
    vis[si][sj] = true;
    if (mat[si][sj] != '-')
        cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj])
        {
            bfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j])
            {
                cnt = 0;
                bfs(i, j);
                if (cnt != 0 && ans > cnt)
                    ans = cnt;
            }
        }
    }
    if (ans != INT_MAX)
        cout << ans;
    else
        cout << -1;

    return 0;
}
