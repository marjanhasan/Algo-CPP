#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N]; // sob gular value 0 ache
bool visited[N];
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
        dfs(v);
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
/*
input:
10
9
1 2
1 3
1 10
2 4
3 5
3 6
4 7
4 8
6 9

output:
visiting node : 1
visiting node : 2
visiting node : 4
visiting node : 7
visiting node : 8
visiting node : 3
visiting node : 5
visiting node : 6
visiting node : 9
visiting node : 10

input:
9
10
1 2
2 3
3 8
1 5
5 4
5 6
4 7
6 7
7 8
8 9

output:
visiting node : 1
visiting node : 2
visiting node : 3
visiting node : 8
visiting node : 7
visiting node : 4
visiting node : 5
visiting node : 6
visiting node : 9

*/