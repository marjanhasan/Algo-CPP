#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int l = 0;
    int r = n - 1;
    bool flag = false;
    int index;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == k)
        {
            flag = true;
            index = mid;
            break;
        }
        (k > a[mid]) ? l = mid + 1 : r = mid - 1;
    }
    (flag == true) ? cout << index << endl : cout << "Not Found" << endl;
    return 0;
}
