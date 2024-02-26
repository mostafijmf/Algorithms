#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[101];
    int fibo(int n, vector<int> &nums)
    {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int ans = max(fibo(n - 1, nums), nums[n - 1] + fibo(n - 2, nums));
        return dp[n] = ans;
    }
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return fibo(nums.size(), nums);
    }
};

int main()
{
    vector<int> nums;
    while (!cin.eof())
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    int ans = s.rob(nums);
    cout << ans;

    return 0;
}