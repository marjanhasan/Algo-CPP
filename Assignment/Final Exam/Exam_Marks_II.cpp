#include <bits/stdc++.h>

using namespace std;
int dp[1005][1005];

bool solve(int n, int a[], int s)
{
    if (n == 0)
        return s == 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (a[n - 1] <= s)
        return dp[n][s] = solve(n, a, s - a[n - 1]) || solve(n - 1, a, s);
    else
        return dp[n][s] = solve(n - 1, a, s);
}

int main()
{
    // Write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int s = abs(1000 - m);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
                dp[i][j] = -1;
        }
        (solve(n, a, s)) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
