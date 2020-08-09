#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll n = 1000000;
ll a[n + 2] = {0};
vector<ll> prime;

void seive()
{
    ll m = 0;
    for (ll i = 2; i <= n; i++)
    {
        a[i] = 1;
    }
    for (ll i = 2; i <= n; i++)
    {
        if (a[i])
        {
            prime.push_back(i);
            //it is a prime number
            for (long int j = i * i; j <= n; j += i)
            {
                a[j] = 0;
            }
        }
    }
}

int main()
{
    seive();
    ll t;
    cin >> t;
    while (t--)
    {
        ll num;
        cin >> num;
        ll high;
        high = lower_bound(prime.begin(), prime.end(), num) - prime.begin();
        if (high == (prime.end() - prime.begin()))
        {
            cout << "out of bound" << endl;
            cout << prime[high - 2] << endl;
        }
        if (num - prime[high - 1] <= prime[high] - num)
        {
            cout << prime[high - 1] << endl;
        }
        else
        {
            cout << prime[high] << endl;
        }
    }
    return 0;
}