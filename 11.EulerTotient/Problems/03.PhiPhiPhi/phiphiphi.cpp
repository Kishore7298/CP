#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll phi(ll n)
{
    ll p = 2, result = n;
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= (result / p);
        }
        p++;
    }
    if (n > 1)
        result -= (result / n);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    while (k--)
    {
        n = phi(n);
    }
    cout << n << endl;
    return 0;
}