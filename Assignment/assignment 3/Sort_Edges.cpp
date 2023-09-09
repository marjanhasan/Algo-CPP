#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int main()
{
    int e;
    cin >> e;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
