#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subset_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    if (a[n - 1] <= s)
        return dp[n][s] = subset_sum(n - 1, a, s - a[n - 1]) || subset_sum(n - 1, a, s);
    else
        return dp[n][s] = subset_sum(n - 1, a, s);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        int s = abs(1000 - m);
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        if (subset_sum(n, a, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}