#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const mod = 1e9 + 7;

ll phi(ll n)
{
    ll result = n, p = 2;
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
        p++;
    }
    if (n > 1)
        result -= result / n;
    return result;
}
ll factor(ll n)
{
    ll result = 1;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result = (result * phi(i) % mod) % mod;
            if (i * i != n)
                result = (result * (phi(n / i) % mod)) % mod;
        }
    }
    return result;
}
int main()
{
    ll N, ans;
    cin >> N;
    ans = factor(N);
    cout << ans;
}