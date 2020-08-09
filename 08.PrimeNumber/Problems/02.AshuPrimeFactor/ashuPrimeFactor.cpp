#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll n = 1000000;
ll a[n + 2] = {0};
unordered_map<ll, ll> factor;

void modifiedSeive()
{
    for (ll i = 0; i < n + 2; i++)
    {
        a[i] = i;
    }
    for (ll i = 2; i < n + 1; i++)
    {
        if (a[i] == i)
        {
            factor[i] = 1;
            for (ll j = i * i; j < n + 1; j += i)
            {
                if (a[j] == j)
                {
                    a[j] = i;
                    factor[i]++;
                }
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
        cout << factor[num];
        cout << endl;
    }
    return 0;
}