#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
// vector<bool> vis(10005);
bool vis[10005];
int dfs(int s)
{

    cout << s << " ";
    vis[s] = true;
    for (auto child : v[s])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
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
    memset(vis, false, sizeof(vis));
    dfs(0);
}