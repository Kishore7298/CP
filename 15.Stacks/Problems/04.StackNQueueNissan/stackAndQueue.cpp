#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll maxSum(ll a[], ll n, ll k)
{
    ll totalSum = 0;
    for (ll i = 0; i < n; i++)
    {
        totalSum += a[i];
    }
    if (n == k)
    {
        return totalSum;
    }
    ll windowLength = n - k;
    ll minSum = 0;
    for (ll i = 1; i <= windowLength; i++)
    {
        minSum += a[i];
    }
    ll tempSum = minSum;
    for (ll i = 2; i < n - windowLength + 1; i++)
    {
        tempSum = tempSum - a[i - 1] + a[i + windowLength - 1];
        if (tempSum < minSum)
        {
            minSum = tempSum;
        }
    }
    return totalSum - minSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << maxSum(a, n, k) << endl;
    return 0;
}