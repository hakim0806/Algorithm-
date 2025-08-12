#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
vector<Edge> edlist;
int const N = 1e5 + 5;
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edlist.push_back(Edge(u, v, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (Edge ed : edlist)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge ed : edlist)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            dis[v] = dis[u] + c;
        }
    }
    if (cycle)
    {
        cout << "cycle found " << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << dis[i] << endl;
        }
    }
}