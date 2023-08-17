#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e5 + 5;
vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);
vector<int> parent(N, -1);

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[N] = true;
        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
            {
                continue;
            }

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
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
        adj[v].push_back({u, w});
    }

    int s, d;
    cin >> s >> d;

    dijkstra(s);

    cout << dist[d] << endl;

    if (dist[d] == INF)
    {
        cout << "No path from " << s << " to " << d << endl;
    }
    else
    {
        vector<int> path;
        int curr = d;

        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        cout << "Shortest path from " << s << " to " << d << ": ";
        for (int v : path)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
directed graph
input:
6 9
1 2 5
2 3 2
1 3 10
3 4 1
4 1 5
1 5 9
5 6 1
2 6 4
2 5 2
4 6

output:
6
Shortest path from 4 to 6: 4 3 2 5 6
*/