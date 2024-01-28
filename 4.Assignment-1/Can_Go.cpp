/*5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char c[1000][1000];
bool vis[1000][1000];
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    else if (c[i][j] == '#') return false;
    return true;
}

bool can_go = false;
void dfs(pair<int, int> src)
{
    int x = src.first;
    int y = src.second;
    if (c[x][y] == 'B')
    {
        can_go = true;
        return;
    }
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
    pair<int, int> src, dst;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            c[i][j] = x;
            if (x == 'A')
                src = {i, j};
            if (x == 'B')
                dst = {i, j};
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(src);

    if (can_go) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
