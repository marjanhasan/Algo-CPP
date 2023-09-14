#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(), dp[n + 1][m + 1];
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
    cout << n + m - dp[n][m];
    return 0;
}
/*
input:
peek
eke

output:
5

input:
ckkgcd
kxgxcyd

output:
9

context:
2 ta string thakbe,
jsb character gula common thakbe taderk ber krte hbe(lcs),
2 ta string thk character common jdi hoy 4 ta that means
total 8 ta character.
amdr kaj jegula mile nai segula + ei 4 ta milay akta notun string banano,
baad porbe 4 ta krn tara common chilo.

tai formula hoilo A string er size + B string er size - lcs;


*/
