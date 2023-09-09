#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];
int a[N];
int solve(int i)
{
    if (i == 1)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    else if (i == 2)
    {
        return dp[i] = abs(a[2] - a[1]);
    }
    else
    {
        int choice1 = solve(i - 1) + abs(a[i] - a[i - 1]);
        int choice2 = solve(i - 2) + abs(a[i] - a[i - 2]);
        return dp[i] = min(choice1, choice2);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        cin >> a[i];
    }
    cout << solve(n) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    return 0;
}