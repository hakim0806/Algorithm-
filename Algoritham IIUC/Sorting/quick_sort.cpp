#include <bits/stdc++.h>
#include <vector>
#define vi vector<long long>
#define ll long long
using namespace std;
ll n;
vi v;
ll partition(ll st, ll end)
{
    ll idx = st - 1;
    ll privot = v[end];
    for (int i = st; i < end; i++)
    {
        if (v[i] <= privot)
        {
            idx++;
            swap(v[i], v[idx]);
        }
    }
    idx++;
    swap(v[idx], v[end]);
    return idx;
}
void Quick_sort(ll st, ll end)
{
    if (st < end)
    {
        ll p_idx = partition(st, end);
        Quick_sort(st, p_idx - 1);
        Quick_sort(p_idx + 1, end);
    }
}
int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Quick_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}