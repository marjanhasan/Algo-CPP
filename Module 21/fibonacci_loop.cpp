#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;
    return 0;
}

/*

1) n input nibo
2) long long wala akta array nibo n+1 size er,
    krn 0 thk n value niye kaj krbo tai
3) array er 0 & 1 index e 1 initialize krbo
4) 2 thk n loop chalabo, 1 kre barbe
5) a[i] er value hbe a[i-1] means ak ghor ager + a[i-2] means 2 ghor ager value
6) print krbo a[n] er value

*/