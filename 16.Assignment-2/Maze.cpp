#include <bits/stdc++.h>
#define pr pair<int, int>
using namespace std;

char mat[1005][1005];
bool vis[1005][1005];
map<pr, pr> mp;

vector<pr> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 1 || i >= n + 1 || j < 1 || j >= m + 1)
        return false;
    else if (mat[i][j] == '#')
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pr> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pr parent = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                mp[{ci, cj}] = parent;
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    pr src;
    pr des;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            mat[i][j] = x;
            if (x == 'R')
                src = {i, j};
            if (x == 'D')
                des = {i, j};
        }
    }
    memset(vis, false, sizeof(vis));
    bfs(src.first, src.second);

    pr match = des;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            pr par = mp[match];
            match = par;
            if (par == src)
                break;
            mat[par.first][par.second] = 'X';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
