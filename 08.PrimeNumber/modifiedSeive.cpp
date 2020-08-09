#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll n = 100000;
ll a[n + 2] = {0};

void modifiedSeive()
{
    for (ll i = 0; i < n + 2; i++)
    {
        a[i] = i;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (a[i] == i)
        {
            for (ll j = i * i; j < n; j += i)
            {
                if (a[j] == j)
                    a[j] = i;
            }
        }
    }
}

int main()
{
    modifiedSeive();
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        while (num != 1)
        {
            cout << a[num] << " ";
            num = num / a[num];
        }
        cout << endl;
    }
    return 0;
}