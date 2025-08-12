#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int w[], int val[], int wi)
{
    if(n == 0 || wi == 0)
    {
        return 0;
    }
    if (w[n - 1] <= wi)
    {
        int op1 = knapsack(n - 1, w, val, wi - w[n - 1]) + val[n - 1];
        int op2 = knapsack(n - 1, w, val, wi);
        return max(op1, op2);
    }
    else
    {
        return knapsack(n - 1, w, val, wi);
    }
}
int main()
{
    int n;
    cin >> n;
    int w[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int wi;
    cin >> wi;
    cout << knapsack(n, w, val, wi) << endl;
}