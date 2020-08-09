#include <iostream>

using namespace std;

void gcd(int a, int b)
{
    if (b == 0)
    {
        cout << a << endl;
    }
    else
    {
        gcd(b, a % b);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    a > b ? gcd(a, b) : gcd(b, a);
    return 0;
}