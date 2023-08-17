#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e5 + 5;
vector<pii> adj[N];
vector<bool> visited(N);
vector<int> dist(N, INF);
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
        visited[u] = true;

        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
                continue;
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
    }

    int s, d;
    cin >> s >> d;

    dijkstra(s);

    cout << dist[d] << endl;

    vector<int> path;
    int curr = d;

    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Path : ";
    for (int v : path)
    {
        cout << v << " ";
    }

    return 0;
}
/*
undirected graph
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
13
Path : 4 1 2 5 6
*/