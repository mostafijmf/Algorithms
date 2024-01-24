#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        // <-- Directed -->
        list[a].push_back(b);

        // <-- Undirected -->
        // list[a].push_back(b);
        // list[b].push_back(a);
    }

    // for (int val : list[0])
    // cout << val << " ";
    for (int i = 0; i < list[3].size(); i++)
    {
        cout << list[3][i] << " ";
    }

    return 0;
}
