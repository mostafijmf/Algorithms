#include <bits/stdc++.h>
using namespace std;
int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        bool a[n + 1];
        memset(a, false, sizeof(a));
        a[1] = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i])
            {
                if (i + 3 <= n)
                    a[i + 3] = true;
                if (i * 2 <= n)
                    a[i * 2] = true;
            }
        }
        cout << (a[n] ? "YES":"NO") << endl;
    }
    return 0;
}
