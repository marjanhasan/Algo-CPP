#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
class Edge
{
public:
    int u;
    int v;
    long long int w;
    Edge(int u, int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    long long int dis[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INF;
    }
    int s;
    cin >> s;
    dis[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (Edge ed : v)
        {
            int a = ed.u;
            int b = ed.v;
            long long int w = ed.w;
            if (dis[a] != INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : v)
    {
        int a = ed.u;
        int b = ed.v;
        long long int w = ed.w;
        if (dis[a] < INF && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int d;
            cin >> d;
            if (dis[d] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    return 0;
}