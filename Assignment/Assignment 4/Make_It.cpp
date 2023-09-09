#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];
bool solve(int i, int n)
{
    if (n == i)
        return true;
    if (i > n)
        return false;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = solve(i + 3, n) || solve(i * 2, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= N; i++)
            dp[i] = -1;
        solve(1, n) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
