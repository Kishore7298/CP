#include <bits/stdc++.h>

using namespace std;

void primeGenerator(int n, vector<int> &prime)
{
    int a[n + 1] = {0};
    for (int i = 2; i <= n; i++)
        a[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                a[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    int l, r;
    cin >> l >> r;
    vector<int> prime;
    primeGenerator(sqrt(r), prime);
    int a[r - l + 1] = {0};
    for (int i = 0; i < r - l + 1; i++)
    {
        a[i] = 1;
    }
    for (auto i : prime)
    {
        int nearestFactor = (l / i) * i;
        if (nearestFactor < l)
        {
            nearestFactor += i;
        }
        for (int j = nearestFactor; j <= r; j += i)
        {
            a[j - l] = 0;
        }
    }
    for (int i = 0; i < r - l + 1; i++)
    {
        if (a[i] == 1)
        {
            cout << l + i << " ";
        }
    }
}