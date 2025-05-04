#include <bits/stdc++.h>
#include <vector>
#define vi vector<long long>
#define ll long long
using namespace std;
const ll N = 102, mod = 1e9 + 7;
ll dp[N][N];
int main()
{
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;  
    }
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = mod;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
            }
        }
    }
    cout << dp[1][n - 1] << endl;

    return 0;
}
