#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int s = abs(1000 - m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int dp[n + 1][s + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= s; i++)
            dp[0][i] = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j && dp[i][j - a[i - 1]] != INT_MAX)
                    dp[i][j] = min(1 + dp[i][j - a[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        (dp[n][s] == INT_MAX) ? cout << -1 << endl : cout << dp[n][s] << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll long long
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int t;
        cin >> t;
        int s = 1000 - t;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int dp[n + 1][s + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= s; i++)
            dp[0][i] = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j && dp[i][j - a[i - 1]] != INT_MAX)
                {
                    dp[i][j] = min(1 + dp[i][j - a[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][s] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dp[n][s] << endl;
    }
    return 0;
}
 */