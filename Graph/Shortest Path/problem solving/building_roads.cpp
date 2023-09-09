#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> l;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        l.push_back(i);
        dfs(i);
    }

    cout << "Leaders: ";
    for (auto v : l)
    {
        cout << v << " ";
    }
    cout << endl;

    cout << "Needed Edges: " << l.size() - 1 << endl;

    cout << "Printing Connections: " << endl;
    for (int i = 1; i < l.size(); i++)
    {
        cout << l[i - 1] << " " << l[i] << endl;
    }
    return 0;
}

/*
input:
8 4
1 2
3 4
5 6
5 7

output:
3
1 3
3 5
5 8

*/
