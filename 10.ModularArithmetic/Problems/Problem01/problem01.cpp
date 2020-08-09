#include <iostream>
#define ll long long
using namespace std;

ll modularExponentiation(ll number, ll power, ll mod)
{
    int base = 1;
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

ll d, x, y;
void extendedEuclid(ll A, ll B)
{
    if (B == 0)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(B, A % B);
        ll temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int main()
{
    ll A, B, C, M;
    cin >> A >> B >> C >> M;
    /*
        Three parts to the computation
        1. (A^B)%M
        2. (C^)%M
        3. (1 * 2)%M
    */
    ll firstPart = modularExponentiation(A, B, M);
    extendedEuclid(C, M);
    ll secondPart = ((x + M) % M) % M;
    ll thirdPart = (firstPart * secondPart) % M;
    cout << thirdPart << endl;
}