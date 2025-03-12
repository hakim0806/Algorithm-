//https://codeforces.com/contest/445/problem/B
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
vector<vector<ll>> v;
bool vis[1005];
ll ans = 1;
void bfs(int src)
{
    queue<ll>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty())
    {
        ll per = q.front();
        q.pop();
        if(per != src)
        {
           ans*=2;
        }
        for( auto child : v[per])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
int main()
{
    ll n,e;
    cin>> n >> e;
    v.resize(n+5);
    while(e--)
    {
        int a,b;
        cin>> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    for(int i = 1; i<=n; i++)
    {
        bfs(i);
    }
    cout << ans << endl;
}