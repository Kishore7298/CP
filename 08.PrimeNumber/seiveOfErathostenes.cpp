#include <bits/stdc++.h>

using namespace std;

const long int n = 1000000;
long int a[n + 2] = {0};

int main()
{
    for (int i = 2; i <= n; i++)
    {
        a[i] = 1;
    }
    for (long int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            //it is a prime number
            for (long int j = i * i; j <= n; j += i)
            {
                a[j] = 0;
            }
        }
    }
    int num;
    cin >> num;
    for (int i = 2; i < num; i++)
    {
        if (a[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}