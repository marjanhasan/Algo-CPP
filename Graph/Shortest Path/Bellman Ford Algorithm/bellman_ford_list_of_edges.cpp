#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
int d[N];
int n, m;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto edges : list_of_edges)
        {
            int u = edges.first.first;
            int v = edges.first.second;
            int w = edges.second;

            if (d[u] != INF && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        list_of_edges.push_back({{u, v}, w});
    }

    bellman_ford(1);

    // to print distance of every single nodes after relaxation
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i;
        cout << ": " << d[i] << endl;
    }
    return 0;
}