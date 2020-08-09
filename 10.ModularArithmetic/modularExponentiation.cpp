#include <iostream>
#define ll long long
using namespace std;

int modularExponentiation(int base, int num, int power, int mod)
{ //recursive approach
    if (num == 0)
    {
        return 1;
    }
    if (power == 1)
    {
        return (base * num) % mod;
    }
    if (power % 2 == 0)
    {
        return modularExponentiation(base, (num * num) % mod, power / 2, mod);
    }
    else
    {
        return modularExponentiation((base * num) % mod, num, power - 1, mod);
    }
}

ll modExponentiation(ll num, ll power, ll mod)
{
    //iterative approach
    ll base = 1;
    while (power > 1)
    {
        if (power % 2 == 0)
        {
            num = (num * num) % mod;
            power /= 2;
        }
        else
        {
            base = (base * num) % mod;
            power--;
        }
    }
    return (base * num) % mod;
}

int main()
{
    ll n, power, mod;
    cin >> n >> power >> mod;
    cout << modExponentiation(n, power, mod) << endl;
    return 0;
}