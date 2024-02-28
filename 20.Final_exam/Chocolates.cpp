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
        int a[n], totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            totalSum += a[i];
        }

        if (totalSum % 2 == 0)
        {
            int div = totalSum / 2;
            bool dp[n + 1][div + 1];
            dp[0][0] = true;
            for (int i = 1; i <= div; i++)
            {
                dp[0][i] = false;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= div; j++)
                {
                    if (a[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }

            if (dp[n][div]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}
