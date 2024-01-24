#include <bits/stdc++.h>
using namespace std;

// <-- Pair like this -->
// class Pair
// {
// public:
//     int first, second;
//     void make_pair(int a, int b)
//     {
//         first = a;
//         second = b;
//     }
// };

int main()
{
    // Pair p;
    // p.make_pair(10, 20);

    // <-- STL Pair -->
    pair<string, int> p;
    p = make_pair("Ami", 20);
    cout << p.first << " " << p.second;
    return 0;
}
