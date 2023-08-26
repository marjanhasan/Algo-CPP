#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1000;
bool vis[N][N];
int dis[N][N];
int n, m;
char a[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pii u = q.front();
        int pi = u.first;
        int pj = u.second;
        q.pop();
        for (auto p : path)
        {
            int ci = pi + p.first;
            int cj = pj + p.second;
            if (isValid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs(si, sj);
    if (si != di && sj != dj)
        (dis[di][dj] > 0) ? cout << "YES" : cout << "NO";
    else
        cout << "YES";
    return 0;
}
