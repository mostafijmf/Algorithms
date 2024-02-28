#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        int a[1005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int dp[n + 1][m + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (a[i - 1] <= j)
                {
                    int opt1 = dp[i - 1][j + a[i - 1]];
                    int opt2 = dp[i - 1][j];
                    dp[i][j] = opt1 + opt2;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        cout << dp[n][m]<< endl;
        // cout << (dp[n][m] ? "YES" : "NO")<< endl;
    }

    return 0;
}
