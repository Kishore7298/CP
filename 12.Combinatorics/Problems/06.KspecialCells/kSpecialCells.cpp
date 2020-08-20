#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

const ll n = 57;
ll factorials[n];        // for storing factorial of number
ll reverseFactorials[n]; // for storing reverse factorial of number

ll power(ll number, ll power)
{ //this function computes modular exponentiation
    ll base = 1;
    while (power != 1)
    {
        if (power % 2 == 0)
        {
            number = (number * number) % mod;
            power = power / 2;
        }
        else
        {
            base = (base * number) % mod;
            power--;
        }
    }
    return (base * number) % mod;
}

void storeFactorials()
{
    factorials[0] = factorials[1] = 1;
    reverseFactorials[0] = reverseFactorials[1] = 1;
    for (int i = 2; i < n; i++)
    {
        factorials[i] = (i * factorials[i - 1]) % mod;
        reverseFactorials[i] = (power(factorials[i], mod - 2)) % mod; //Fermat's theorem (as mod is prime)
    }
}

ll nCr(ll n, ll r)
{ //this function returns (nCr)%mod
    ll nFact = factorials[n];
    ll nMinusR = reverseFactorials[n - r];
    ll rFact = reverseFactorials[r];
    return ((nFact * nMinusR) % mod * rFact) % mod;
}

int main()
{
    storeFactorials();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll totalStrength = 0;
        while (k--)
        {
            ll localStrength = 1;
            ll x, y, strength;
            cin >> x >> y >> strength;
            localStrength *= nCr(y + x - 2, x - 1);                            // the number of ways from (1,1) -> (x,y).
            localStrength = (localStrength * nCr(n - x + m - y, n - x)) % mod; // the number of ways from (x,y) -> (n,m).
            localStrength = (localStrength * strength) % mod;                  // Total local strength from single special cell.
            totalStrength = (totalStrength + localStrength) % mod;             //Computing the total strength from all special cells
        }
        cout << totalStrength << endl;
    }
    return 0;
}