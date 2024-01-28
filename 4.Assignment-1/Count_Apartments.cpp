#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char c[1000][1000];
bool vis[1000][1000];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else if (c[i][j] == '#')
        return false;
    return true;
}

void dfs(pair<int, int> src)
{
    int x = src.first;
    int y = src.second;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int new_i = x + d[i].first;
        int new_j = y + d[i].second;
        if (valid(new_i, new_j) && !vis[new_i][new_j])
        {
            dfs({new_i, new_j});
        }
    }
}

int main()
{
    queue<pair<int, int>> q;
    bool found = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            c[i][j] = x;
            if (x == '.')
            {
                q.push({i, j});
            }
        }
    }
    memset(vis, false, sizeof(vis));

    int count_apt = 0;

    while (!q.empty())
    {
        pair<int, int> src = q.front();
        if (!vis[src.first][src.second])
        {
            dfs(src);
            count_apt++;
        }
        q.pop();
    }
    cout << count_apt;

    return 0;
}
