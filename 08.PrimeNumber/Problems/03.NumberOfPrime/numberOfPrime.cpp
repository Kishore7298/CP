#include <iostream>
#define ll long long

using namespace std;

const ll n = 1000001;
ll a[n] = {0};

void countSeive()
{
    for (int i = 2; i < n; i++)
        a[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i] == 1)
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
    }
    for (int i = 3; i < n; i++)
        a[i] = a[i] + a[i - 1];
}

int main()
{
    int n;
    countSeive();
    cin >> n;
    cout << a[n] << endl;
}
