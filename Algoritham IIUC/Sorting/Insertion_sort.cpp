#include <bits/stdc++.h>
#include <vector>
#define vi vector<long long>
#define ll long long
using namespace std;
ll n;
vi v;
void insertion_sort()
{
    for(int i = 1; i<n; i++)
    {
        ll cur = v[i];
        ll prev = i -1;
        while(prev >= 0 && v[prev] > cur)
        {
            v[prev+1] = v[prev];
            prev--; 
        }
        v[prev+1] = cur;
    }
}
int main()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i<n; i++)
    {
        cin>> v[i];
    }
    insertion_sort();
    for(int i = 0; i<n; i++)
    {
      cout <<  v[i] << " ";
    }
}