#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool fact(ll v, ll n)
{
    if (v == n)
        return true;
    else if (v > n)
        return false;

    return fact(v * 10, n) || fact(v * 20, n);
}
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        cout << (fact(1, n) ? "YES" : "NO") << endl;
    }

    return 0;
}
