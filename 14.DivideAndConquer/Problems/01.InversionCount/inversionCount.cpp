#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll counter;

void merge(ll a[], ll l, ll m, ll h)
{
    vector<ll> sorted;
    ll start = l;
    ll mid = m + 1;
    while (start <= m && mid <= h)
    {
        if (a[start] < a[mid])
            sorted.push_back(a[start++]);
        else
        {
            counter += m - start + 1;
            sorted.push_back(a[mid++]);
        }
    }
    while (start <= m)
        sorted.push_back(a[start++]);
    while (mid <= h)
    {
        sorted.push_back(a[mid++]);
    }
    for (ll i = l; i <= h; i++)
    {
        a[i] = sorted[i - l];
    }
}

void mergeSort(ll a[], ll low, ll high)
{
    if (high <= low)
        return;

    ll mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        counter = 0;
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        mergeSort(a, 0, n - 1);
        cout << counter << endl;
    }
    return 0;
}