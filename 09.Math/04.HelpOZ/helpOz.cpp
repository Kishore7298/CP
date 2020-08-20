#include <bits/stdc++.h>
#define ll long long

using namespace std;

void findFactors(ll n, vector<ll> &factors)
{
    factors.push_back(n);
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i * i != n)
                factors.push_back(n / i);
        }
    }
}

void printK(ll a[], int m)
{
    ll diff = abs(int(a[1] - a[0]));
    vector<ll> factors;
    findFactors(diff, factors);
    sort(factors.begin(), factors.end());
    vector<ll> k;
    for (auto i : factors)
    {
        bool flag = true;
        ll kmod = a[0] % i;
        for (int j = 1; j < m; j++)
        {
            if ((a[j] % i) != kmod)
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            k.push_back(i);
        }
    }
    for (auto i : k)
    {
        cout << i << " ";
    }
}

int main()
{
    int m;
    cin >> m;
    ll a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    printK(a, m);
}