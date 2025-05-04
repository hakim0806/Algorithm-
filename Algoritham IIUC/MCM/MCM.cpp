#include <bits/stdc++.h>
#include <vector>
#define vi vector<long long>
#define ll long long
using namespace std;
vi v;
const ll N = 102, mod = 1e9 + 7;
ll dp[N][N];

ll mcm(ll i, ll j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = mod;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], mcm(i, k) + mcm(k + 1, j) + v[i - 1] * v[k] * v[j]);
    }
    return dp[i][j];
}

int main()
{
    ll n;
    cin >> n;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << mcm(1, n - 1) << endl;
}