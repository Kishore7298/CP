#include <bits/stdc++.h>

using namespace std;

int power(int number, int pwr, int base)
{
    if (pwr <= 1)
    {
        return base * number;
    }

    if (pwr % 2 != 0)
        return power(number, pwr - 1, base * number);
    else
        return power(number * number, pwr / 2, base);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int number, pwr;
        cin >> number >> pwr;
        cout << power(number, pwr, 1) << endl;
    }
    return 0;
}