#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[n + 1][n + 1], w[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        w[i] = i + 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][n];
    return 0;
}
