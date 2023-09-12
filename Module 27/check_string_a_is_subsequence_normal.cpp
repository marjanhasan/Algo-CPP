#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    /* normal approach O(M)

    int x = 0;
    bool ans = false;
    for (char c : b)
    {
        if (c == a[x])
            x++;
        if (x == n)
        {
            ans = true;
            break;
        }
    }
    ans ? cout << "YES" : cout << "NO"; */

    // lcs O(N*M)
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    (dp[n][m] == n) ? cout << "YES" : cout << "NO";
    return 0;
}
/*
input:
axe
bkazxkjxkel

output:
YES

input:
axe
bkazxkjxkl

output:
NO
 */
