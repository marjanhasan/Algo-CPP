#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int dp[n + 1][s + 1], v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
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
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " "
                 << "  ";
        }
        cout << endl;
    }
    cout << dp[n][s] << endl;
    return 0;
}
/*
input:
4 6
5 3 2 4
4 1 3 2
output:
18
*/