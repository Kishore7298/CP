#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    unordered_map<ll, ll> frequency;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (frequency.find(a[i]) == frequency.end())
        {
            frequency.insert(make_pair(a[i], 1));
        }
        else
        {
            frequency[a[i]] = frequency[a[i]] + 1;
        }
    }
    ll max = frequency[a[0]];
    for (auto i : frequency)
        if (i.second > max)
            max = i.second;

    cout << n - max << endl;
    return 0;
}