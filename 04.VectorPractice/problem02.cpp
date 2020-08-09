#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int elements;
    for (int i = 0; i < n; i++)
    {
        cin >> elements;
        a.push_back(elements);
    }
    int q;
    cin >> q;
    int queryElement;
    for (int i = 0; i < q; i++)
    {
        cin >> queryElement;
        int index = lower_bound(a.begin(), a.end(), queryElement) - a.begin();
        if (index != n && a[index] == queryElement)
        {
            cout << "Yes " << index + 1 << endl;
        }
        else
        {
            cout << "No " << index + 1 << endl;
        }
    }
    return 0;
}