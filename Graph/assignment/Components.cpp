#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int sum;
void dfs(int u)
{
    visited[u] = true;
    sum++;
    for (int v : adj[u])
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

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        sum = 0;
        dfs(i);
        if (sum > 1)
            v.push_back(sum);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}