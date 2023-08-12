#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool isCycleExist = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        isCycleExist = isCycleExist | dfs(v, u);
    }
    return isCycleExist;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // if (dfs(1))
    //     cout << "Cycle detected!\n";
    // else
    //     cout << "Cycle is not detected!\n";

    bool isCycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle |= dfs(i);
    }
    isCycle ? cout << "Cycle detected\n" : cout << "No cycle detected!\n";
    return 0;
}
