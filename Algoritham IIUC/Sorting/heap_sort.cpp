#include <bits/stdc++.h>
#include <vector>
#define vi vector<long long>
#define ll long long
using namespace std;
vi heap;
vi heap_sort;
void insert(int v)
{
    heap.push_back(v);
    ll cur = heap.size() - 1;
    while (cur != 0)
    {
        ll pr = (cur - 1) / 2;
        if (heap[pr] < heap[cur])
        {
            swap(heap[pr], heap[cur]);
        }
        else
        {
            break;
        }
        cur = pr;
    }
}
void del()
{
    heap_sort.push_back(heap[0]);
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    ll cur = 0;
    while (1)
    {
        ll l = cur * 2 + 1;
        ll r = cur * 2 + 2;
        ll lst = heap.size() - 1;
        if (l <= lst && r <= lst)
        {
            // 2ti ache
            if (heap[l] >= heap[r] && heap[l] > heap[cur])
            {
                swap(heap[l], heap[cur]);
                cur = l;
            }
            else if (heap[r] >= heap[l] && heap[r] > heap[cur])
            {
                swap(heap[r], heap[cur]);
                cur = r;
            }
            else
            {
                break;
            }
        }
        else if (l <= lst)
        {
            if (heap[l] > heap[cur])
            {

                swap(heap[l], heap[cur]);
                cur = l;
            }
            else
            {
                break;
            }
        }
        else if (r <= lst)
        {
            if (heap[r] > heap[cur])
            {
                swap(heap[r], heap[cur]);
                cur = r;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        insert(x);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << heap[i] << " ";
    // }
    for (int i = 0; i < n; i++)
    {
        del();
    }
    for(int x : heap_sort)
    {
        cout << x << " ";
    }
}