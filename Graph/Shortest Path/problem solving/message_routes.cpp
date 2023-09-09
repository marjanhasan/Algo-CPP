#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> visited(N, false);
vector<int> level(N, 0);
vector<int> parent(N, -1);

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            level[v] = level[u] + 1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    // cout << level[n] << endl;

    int curr = n;
    int routes = 0;
    vector<int> path;

    while (curr != -1)
    {
        routes++;
        path.push_back(curr);
        curr = parent[curr];
    }

    if (path.empty() || routes == 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(path.begin(), path.end());
    cout << routes << endl;
    for (auto p : path)
    {
        cout << p << " ";
    }
    return 0;
}
/*
input:
5 5
1 2
1 3
2 3
1 4
4 5

output:
3
1 4 5
*/