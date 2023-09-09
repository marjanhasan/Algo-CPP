/*  top down approach
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapsack(int n, int W, int w[], int v[])
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (w[n - 1] <= W)
        return dp[n][W] = max(knapsack(n - 1, W - w[n - 1], w, v) + v[n - 1], knapsack(n - 1, W, w, v));
    else
        return dp[n][W] = knapsack(n - 1, W, w, v);
}
int main()
{
    int n, W;
    cin >> n >> W;
    int w[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, W, w, v);
    return 0;
}
 */
// bottom up approach
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int w[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    int dp[n + 1][s + 1];
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         if (i == 0 || j == 0)
    //             dp[i][j] = 0;
    //     }
    // }
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
                dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s];
    return 0;
}
