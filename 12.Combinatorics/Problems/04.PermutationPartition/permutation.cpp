#include <bits/stdc++.h>
#define ll long long
#define mod 998244353

using namespace std;

void printMax(ll a[], ll n, ll k)
{
    unordered_set<ll> maxElements;
    ll max = 0;
    ll temp = n;
    for (ll i = 0; i < k; i++)
    {
        max += temp;
        maxElements.insert(temp);
        temp--;
    }
    if (n == k)
        cout << max << " " << 1 << endl;
    else
    {
        ll finalProduct = 1;
        ll localCount = 0;
        int foundMax = 0;
        for (ll i = 0; i < n; i++)
        {
            if (maxElements.find(a[i]) != maxElements.end())
                //elemet is max element
                foundMax++;
            else if (foundMax == 1)
                localCount++;
            if (foundMax == 2)
            {
                finalProduct = (finalProduct * (localCount + 1)) % mod;
                localCount = 0;
                foundMax--;
            }
        }
        cout << max << " " << finalProduct << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printMax(a, n, k);
    return 0;
}