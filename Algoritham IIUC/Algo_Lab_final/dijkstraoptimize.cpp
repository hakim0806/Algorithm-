#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
vector<pr> v[1000];
int dis[10000];
class cmp
{
public:
    bool operator()(pr a, pr b)
    {
        return a.second > b.second;
    }
};
int dijkstra(int sr)
{
    // queue<pr>q;
    priority_queue<pr, vector<pr>, cmp> q;
   // priority_queue<int,vector<int>,cmp>q
    q.push({sr, 0});
    dis[sr] = 0;
    while ((!q.empty()))
    {
        pr par = q.top();
        q.pop();
        int node = par.first;
        int cost = par.second;
        for (auto child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, cost + childCost});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    int inf = INT_MAX;
    // memset(dis,inf,sizeof(dis));
    for (int i = 0; i < n; i++)
    {
        dis[i] = inf;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
}