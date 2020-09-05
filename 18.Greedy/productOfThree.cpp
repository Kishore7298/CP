#include <bits/stdc++.h>
#define int long long
using namespace std;

void productOfThree(int n)
{
    int a, b, c;
    bool filledA = false, filledB = false;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            if (filledA == false)
            {
                a = i;
                filledA = true;
                n = n / a;
            }
            else if (filledB == false)
            {
                filledB = true;
                b = i;
                c = n / b;
                break;
            }
        }
        i++;
    }
    if (filledA && filledB)
        if (c != a && c != b)
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    else
        cout << "NO" << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        productOfThree(n);
    }

    return 0;
}