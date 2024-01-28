#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> v[], int x)
{
    if (!v[x].empty())
    {
        vector<int> cnt;
        for (int child : v[x])
        {
            cnt.push_back(child);
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        for (int val : cnt)
            cout << val << " ";
    }
    else cout << -1;
    cout << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[1000];
    bool vis[1000];
    memset(vis, false, sizeof(vis));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        vis[a] = true;
        vis[b] = true;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (vis[x])
        {
            bfs(v, x);
        }
        else cout << -1 << endl;
    }

    return 0;
}
