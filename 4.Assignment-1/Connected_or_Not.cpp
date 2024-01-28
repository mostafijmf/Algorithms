#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        bool exist = false;
        if (a == b) exist = true;
        else
        {
            for (int child : v[a])
            {
                if (child == b)
                {
                    exist = true;
                    break;
                }
            }
        }

        if (exist) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
