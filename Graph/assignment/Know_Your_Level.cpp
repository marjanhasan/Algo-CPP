#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
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
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int l;
    cin >> l;
    bfs(0);
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        if (level[i] == l)
        {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    if (l == 0)
        cout << 0;
    else if (!v.empty())
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}