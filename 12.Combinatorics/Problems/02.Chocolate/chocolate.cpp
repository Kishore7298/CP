#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bites(int a[], int n)
{
    ll count = 1;
    ll countZero = 0;
    ll foundOne = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            foundOne++;
        }
        if (foundOne == 1)
        {
            if (a[i] == 0)
            {
                countZero++;
            }
        }
        if (foundOne == 2)
        {
            count *= (countZero + 1);
            foundOne--;
            countZero = 0;
        }
    }
    if (foundOne == 0)
    {
        return 0;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << bites(a, n) << endl;
    return 0;
}