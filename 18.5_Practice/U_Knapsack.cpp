#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int knapsack(int n, int weight[], int value[], int W)
{
    if (n < 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];

    if (weight[n] <= W)
    {
        int opt1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int opt2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = max(opt1, opt2);
    }
    else
    {
        int opt2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = opt2;
    }
}
int main()
{
    int n, W;
    cin >> n >> W;
    int weight[n], value[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, weight, value, W);

    return 0;
}
