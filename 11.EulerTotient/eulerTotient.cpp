#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll length = 1000007;
int prime[length] = {0};

void modifiedSeive()
{
    for (ll i = 1; i < length; i++)
    {
        prime[i] = i;
    }
    for (ll i = 2; i * i <= length; i++)
    {
        if (prime[i] == i)
        {
            for (ll j = i * i; j < length; j += i)
            {
                if (prime[j] == j)
                {
                    prime[j] = i;
                }
            }
        }
    }
}

ll eulerTotient(ll n)
{
    unordered_set<ll> primeFactors;
    ll temp = n;
    while (temp != 1)
    {
        ll elem = prime[temp];
        primeFactors.insert(elem);
        temp = temp / elem;
    }
    ll ans = n;
    for (auto i : primeFactors)
    {
        ans = ans - (ans / i);
    }
    return ans;
}

int main()
{
    modifiedSeive();
    ll n;
    cin >> n;
    cout << eulerTotient(n) << endl;
    return 0;
}