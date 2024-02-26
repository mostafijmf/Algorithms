#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll mat[20][20];
bool vis[20][20];

ll fibo(int i, int j) {
    if (i == n && j == m) return mat[i][j];    
    if (vis[i][j]) return 0;

    vis[i][j] = true;
    ll ans = INT_MIN;

    if (i < n) ans = max(ans, fibo(i + 1, j) + mat[i][j]);
    if (j < m) ans = max(ans, fibo(i, j + 1) + mat[i][j]);

    vis[i][j] = false;
    return ans;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            vis[i][j] = false;
        }
    }

    cout << fibo(1, 1);
    return 0;
}
