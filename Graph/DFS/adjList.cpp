#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
// vector<int> adj[N]; // sob gular value 0 ache
vector<pair<int, int>> adj[N]; // weighted graph
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        /*
        unweighted graph
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected hle ei line add krbo */
        adj[u].push_back({v, w}); // push_back(make_pair(v,w))
        adj[v].push_back({u, w}); // push_back(make_pair(v,w))
    }

    /*
    directed unweighted graph
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/

    // undirected weighted graph
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (auto j : adj[i])
        {
            cout << "( " << j.first << ", " << j.second << " ), ";
        }
        cout << endl;
    }
    return 0;
}