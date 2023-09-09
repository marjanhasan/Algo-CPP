#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 + 10;
vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // pq nibo pair er r greater use krbo jate min to max sorted hoy
    dist[source] = 0;
    // source node er distance 0 set krbo
    pq.push({dist[source], source});
    // pq te node er distance r node rakhbo.
    // first = distance_of_node second = node
    // age distance rakhbo krn distance akare sort krtesi

    while (!pq.empty())
    {
        int u = pq.top().second;
        // pq thk node er value ta nibo
        // jeta hbe amdr parent node
        pq.pop();
        visited[u] = true;
        // node take visited kre dibo

        // parent thk child ber krar loop
        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            // v = child node
            int w = vpair.second;
            // w = weight

            if (visited[v])
                continue;
            // visited thakle ignore krlam

            /*
            child node er distance jdi,
            parent noder er distance + edge er weight thk
            beshi hoy tbe block e dhukbe
            */
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                // child node er destination update hbe
                pq.push({dist[v], v});
                // child node er destination r child node push hbe
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

    dijkstra(1);
    /*
    evabe amra vector er vetore child node er info gula rakhtesi
    (2,3) (3,4)
    (1,3) (4,2)
    (1,4) (4,1)
    (2,2) (3,1)
    for (int i = 0; i <= n; i++)
        {
            cout << "vertex " << i << " is connected with: ";
            for (pii vpair : adj[i])
            {
                cout << "( " << vpair.first << " , " << vpair.second << " ) ";
            }
            cout << endl;
        }
    output:
    vertex 0 is connected with:
    vertex 1 is connected with: ( 2 , 3 ) ( 3 , 4 )
    vertex 2 is connected with: ( 1 , 3 ) ( 4 , 2 )
    vertex 3 is connected with: ( 1 , 4 ) ( 4 , 1 )
    vertex 4 is connected with: ( 2 , 2 ) ( 3 , 1 )
    */
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
/*
input:
4 4
1 2 3
1 3 4
2 4 2
3 4 1

output:
distance of 1 : 0
distance of 2 : 3
distance of 3 : 4
distance of 4 : 5

*/