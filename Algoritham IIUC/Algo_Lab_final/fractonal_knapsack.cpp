#include <bits/stdc++.h>
using namespace std;
class Item
{
public:
    int value, weight;
    Item() {}
    Item(int v, int w)
    {
        value = v;
        weight = w;
    }
};
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;
    for (auto item : items)
    {
        if (W == 0)
            break;

        if (item.weight <= W)
        {
            totalValue += item.value;
            W -= item.weight;
        }
        else
        {
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }
    return totalValue;
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        int val, wt;
        cin >> val >> wt;
        items[i] = Item(val, wt);
    }
    double maxValue = fractionalKnapsack(W, items);
    cout << fixed << setprecision(4) << maxValue << endl;
    return 0;
}
