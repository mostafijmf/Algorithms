#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    int smallFact = fact(n - 1);
    return smallFact * n;
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}
