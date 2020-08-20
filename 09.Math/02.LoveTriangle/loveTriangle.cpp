#include <bits/stdc++.h>
using namespace std;

long long base9(long long n)
{
    if (n < 9)
    {
        return n;
    }
    else
    {
        return (n % 9 + 10 * base9(n / 9));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (!cin.eof())
    {
        long long n;
        cin >> n;
        cout << base9(n) << '\n';
    }
}