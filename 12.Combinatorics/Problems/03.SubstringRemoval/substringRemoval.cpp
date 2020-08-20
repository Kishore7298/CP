#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll removeSubString(string s, ll n)
{
    if (n == 2)
        return 3;

    ll count = 1;
    ll beginCount = 1;
    char beginChar = s[0];
    bool midChar = false;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            beginCount = (beginCount + 1) % mod;
        else
        {
            midChar = true;
            count = (count + beginCount) % mod;
            break;
        }
    }
    ll endCount = 1;
    char endChar = s[n - 1];
    if (midChar == true)
    {
        for (ll i = n - 2; i >= 0; i--)
        {
            if (s[i] == s[i + 1])
                endCount = (endCount + 1) % mod;
            else
            {
                count = (count + endCount) % mod;
                break;
            }
        }
        if (beginChar == endChar)
        {
            count = ((beginCount + 1) * (endCount + 1)) % mod;
        }
    }
    else
    {
        count = (count + beginCount) % mod;
    }
    return (count) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    cout << removeSubString(s, n) << endl;
    return 0;
}