#include <iostream>

using namespace std;

int main()
{
    int a[1000000];
    a[0] = 0;
    for (int i = 1; i < 1000000; i++)
    {
        int lastNum = i % 10;
        if (lastNum == 2 || lastNum == 3 || lastNum == 9)
        {
            a[i] = 1 + a[i - 1];
        }
        else
        {
            a[i] = 0 + a[i - 1];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
    return 0;
}