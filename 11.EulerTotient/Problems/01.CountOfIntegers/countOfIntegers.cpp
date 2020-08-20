#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll n = 1000006;
ll a[n + 2] = {0};

void modifiedSeive()
{
    for (ll i = 0; i < n; i++)
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

ll modifiedEuler(ll n)
{
    unordered_set<ll> uniquePrime;
    ll factorCount = 1;
    ll temp = n;
    ll lastElem = a[temp];
    ll count = 0;
    while (temp != 1)
    {
        ll elem = a[temp];
        if (elem != lastElem)
        {
            count++;
            factorCount *= count;
            count = 0;
            lastElem = elem;
        }
        uniquePrime.insert(elem);
        count++;
        temp = temp / elem;
    }
    if (count != 0)
    {
        count++;
        factorCount *= count;
    }
    ll ans = n;
    for (auto i : uniquePrime)
        ans = ans - (ans / i);
    return n - factorCount - ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    modifiedSeive();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << modifiedEuler(n) << endl;
    }
    return 0;
}