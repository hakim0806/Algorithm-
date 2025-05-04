#include <bits/stdc++.h>
#include <vector>
#define vi vector<long long>
#define ll long long
using namespace std;
ll n;
vi v;
void marge(ll l, ll mid, ll r)
{
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    vi a(n1);
    vi b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = v[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = v[mid + 1 + i];
    }
    ll i = 0;
    ll j = 0;
    ll k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            v[k] = a[i];
            i++;
            k++;
            
        }
        else
        {
            v[k] = b[j];
            j++;
            k++;
            
        }
    }
    while (i < n1)
    {
        v[k] = a[i];
        i++;
        k++;
        
    }
    while (j < n2)
    {
        v[k] = b[j];
        j++;
        k++;
        
    }
}
void Marge_sort(ll l, ll r)
{
    if (l < r)
    {
        ll mid = (l + r) / 2;
        Marge_sort(l, mid);
        Marge_sort(mid + 1, r);
        marge(l, mid, r);
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
    Marge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}