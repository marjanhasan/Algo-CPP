#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int rod_cutting(int n, int s, int w[], int v[])
{
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        return dp[n][s] = max(rod_cutting(n, s - w[n - 1], w, v) + v[n - 1], rod_cutting(n - 1, s, w, v));
    }
    else
        return dp[n][s] = rod_cutting(n - 1, s, w, v);
}
int main()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        w[i] = i + 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rod_cutting(n, n, w, v);
    return 0;
}
