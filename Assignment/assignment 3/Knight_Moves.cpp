#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
int t, n, m, ki, kj, qi, qj;
int vis[N][N];
int dis[N][N];
vector<pii> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : dir)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !vis[ni][nj])
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
                dis[ni][nj] = dis[i][j] + 1;
            }
        }
    }
}

void reset_level_vis()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = 0;
            vis[i][j] = false;
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> ki >> kj;
        cin >> qi >> qj;
        if (ki == qi && kj == qj)
        {
            cout << 0 << endl;
            continue;
        }
        bfs(ki, kj);
        if (dis[qi][qj] > 0)
            cout << dis[qi][qj] << endl;
        else
            cout << -1 << endl;
        reset_level_vis();
    }
    return 0;
}
