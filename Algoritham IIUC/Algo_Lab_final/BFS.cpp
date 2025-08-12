#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
// vector<bool> vis(10005);
bool vis[10005];
int bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    while ((!q.empty()))
    {
        int per = q.front();
        q.pop();
        cout << per << " ";
        for(auto child : v[per])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
    
}
int main()
{
    int n , e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // for(int i = 0; i<n; i++)
    // {
    //     cout << i << ": ";
    //     for(auto x : v[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    memset(vis,false,sizeof(vis));
    bfs(0);
}