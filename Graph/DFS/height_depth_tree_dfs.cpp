#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N]; // sob gular value 0 ache
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    // step 1: actions needs to be taken just after entering node u
    visited[u] = true;
    cout << "visiting node : " << u << endl;
    for (int v : adj[u])
    {
        // step 2: actions needs to  be taken before entering a new/unvisited neighbor/child
        if (visited[v])
            continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        /*
        if (height[v] + 1 > height[u])
            height[u] = height[v] + 1;
        */
        height[u] = max(height[u], height[v] + 1);
        // step 3: actions needs to be taken after exiting a neighbor
    }
    // step 4: actions needs to be taken before exiting node u
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // unweighted graph
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected hle ei line add krbo
    }

    /* directed unweighted graph
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/

    dfs(1);

    return 0;
}