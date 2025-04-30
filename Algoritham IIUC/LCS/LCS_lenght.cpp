#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1005][1005];
ll LCS_LENGHT(string a, ll n, string b, ll m)
{
    if (n == 0 or m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (a[n - 1] == b[m - 1])
    {
        ll ans = LCS_LENGHT(a, n - 1, b, m - 1);
        return dp[n][m] = ans + 1;
    }
    else
    {
        ll ans1 = LCS_LENGHT(a, n - 1, b, m);
        ll ans2 = LCS_LENGHT(a, n, b, m - 1);
        return dp[n][m] = max(ans1, ans2);
    }
}
int main()
{
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    ll l = LCS_LENGHT(a, a.size(), b, b.size());
    cout << l << endl;
}