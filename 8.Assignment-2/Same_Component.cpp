#include <bits/stdc++.h>
using namespace std;

char c[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> mv = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    else if (c[i][j] == '-') return false;
    return true;
}

bool same = false;
void dfs(int s1, int s2, int d1, int d2)
{
    int x = s1;
    int y = s2;
    if (x == d1 && y == d2)
    {
        same=true;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int new_i = x + mv[i].first;
        int new_j = y + mv[i].second;
        if (valid(new_i, new_j) && !vis[new_i][new_j])
        {
            dfs(new_i, new_j, d1, d2);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int s1, s2, d1, d2;
    cin >> s1 >> s2 >> d1 >> d2;
    dfs(s1, s2, d1, d2);

    if (same) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
