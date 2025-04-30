#include <bits/stdc++.h>
#include <vector>
int i, j, x;
#define ll long long
#define vi vector<long long>
#define v_input(v, n)           \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    };
#define v_output(v, n)          \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << v[i] << " ";    \
    }                           \
    cout << endl;
using namespace std;
ll n;
vi v;
void count_sort()
{
 
    ll mx = *max_element(v.begin(),v.end());
    mx = mx+1;
    vi cnt(mx,0);
    for(int i = 0; i<n; i++)
    {
        cnt[v[i]]++;
    }
  
    for(int i = 1; i<mx; i++)
    {
        cnt[i] +=cnt[i-1];
    }
    vi arr(n);
    for(int i = n-1; i>=0; i--)
    {
        arr[--cnt[v[i]]] = v[i];
    }
    for(int x : arr)
    {
        cout << x << " ";
    }
}
int main()
{
    //cout << " heee";
    cin>>n;
    v.resize(n);
    v_input(v,n);
    count_sort();
    return 0;
}
