#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

const ll length = 1000006;
bool prime[length] = {false};
ll primeSum[length] = {0};
void modifiedSeive()
{
    memset(prime, true, sizeof(prime));
    for (ll i = 2; i * i <= length; i++)
    {
        if (prime[i] == true)
        {
            for (ll j = i * i; j < length; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (ll i = 2; i < length; i++)
    {
        if (prime[i] == true)
        {
            primeSum[i] = primeSum[i - 1] + i;
        }
        else
        {
            primeSum[i] = primeSum[i - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    modifiedSeive();
    cin >> n;
    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        cout << primeSum[r] - primeSum[l - 1] << endl;
    }
    return 0;
}