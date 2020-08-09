#include <bits/stdc++.h>
#define ll long long

ll mod = 1000000000 + 7;

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll gcdOfArray(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        ll result = a[0];
        for (int i = 1; i < n; i++)
        {
            result = gcd(a[i], result);
            if (result == 1)
            {
                return 1;
            }
        }
        return result;
    }
}

ll modularExponentiation(ll n, int p)
{
    if (p == 0)
        return 1;

    if (p == 1)
        return n;

    ll base = 1;
    while (p != 1)
    {
        if (p % 2 == 0)
        {
            n = (n * n) % mod;
            p /= 2;
        }
        else
        {
            base = (base * n) % mod;
            p--;
        }
    }
    return (base * n) % mod;
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
    ll gcd = gcdOfArray(a, n);
    ll product = 1;
    for (int i = 0; i < n; i++)
    {
        product = (product * modularExponentiation(a[i], gcd)) % mod;
    }
    cout << product % mod << endl;

    return 0;
}