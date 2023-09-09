#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1005;
bool vis[N][N];
int n, m, cnt;
char a[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (auto p : path)
    {
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            dfs(ci, cj);
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
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }
    }
    if (cnt > 0)
        cout << mn;
    else
        cout << -1;

    return 0;
}
