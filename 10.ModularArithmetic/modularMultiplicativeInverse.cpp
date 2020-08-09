#include <iostream>

using namespace std;

int d, x, y;

void extendedEucledian(int A, int B)
{
    if (B == 1)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEucledian(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int main()
{
    int A, mod;
    cin >> A >> mod;
    extendedEucledian(A, mod);
    cout << (x % mod + mod) % mod << endl; //x can be negative so making it positive.
    return 0;
}