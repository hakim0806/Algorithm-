#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
// vector<bool> vis(10005);
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[20][20];
char c[20][20];
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
int dfs(int si, int sj)
{
    stack<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while ((!q.empty()))
    {
        auto per = q.top();
        int a = per.first, b = per.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
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
            cin >> c[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);
}