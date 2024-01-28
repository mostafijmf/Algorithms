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

void dfs(pair<int, int> src, int &cr)
{
    int x = src.first;
    int y = src.second;
    cr++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int new_i = x + d[i].first;
        int new_j = y + d[i].second;
        if (valid(new_i, new_j) && !vis[new_i][new_j])
        {
            dfs({new_i, new_j}, cr);
        }
    }
}

int main()
{
    queue<pair<int, int>> q;
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

    vector<int> cnt;
    while (!q.empty())
    {
        pair<int, int> src = q.front();
        if (!vis[src.first][src.second])
        {
            int cr = 0;
            dfs(src, cr);
            cnt.push_back(cr);
        }
        q.pop();
    }
    
    if (!cnt.empty())
    {
        sort(cnt.begin(), cnt.end());
        for (int val : cnt) cout << val << " ";
    }
    else cout << 0;

    return 0;
}
