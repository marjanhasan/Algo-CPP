#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> v;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        Edge ed(a, b, w);
        // cout << ed.u << " " << ed.v << " " << ed.w << endl;
        // evabe individual src,des & cost print kra jay
        v.push_back(ed);
    }

    int dis[n + 1];
    // krn 1 thk 4 holo node.
    // size 4 thakle 0 to 3 count hbe.
    // plus 1 kre dile 1 to 4 track rakhte parbe

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1] = 0; // src tare 0 kre dibo

    // n-1 bar loop chalabo
    // proti bar protita edge relax hbe
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;

            // relaxation krbo
            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }

    return 0;
}
/*
find the shortes path,
using bellman ford algorithm.
when the cost is negative and,
might be in negative cycle.
must be directed

input:
4 4
1 2 5
2 3 2
3 4 -2
1 4 10

output:
Node 1: 0
Node 2: 5
Node 3: 7
Node 4: 5
*/