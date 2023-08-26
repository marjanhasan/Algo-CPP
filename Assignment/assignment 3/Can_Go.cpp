#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1e3 + 5;
const int INF = 1e9 + 10;
vector<pii> adj[N];
vector<int> dis(N, INF);
vector<bool> vis(N);

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s] = 0;
    pq.push({dis[s], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;
            if (vis[v])
                continue;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int s, t;
    cin >> s >> t;
    dijkstra(s);
    while (t--)
    {
        int d, dw;
        cin >> d >> dw;
        if (dis[d] <= dw)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
