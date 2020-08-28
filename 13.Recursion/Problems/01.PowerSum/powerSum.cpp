#include <bits/stdc++.h>
#define ll long long
using namespace std;

int totalCount = 0;

void calcCount(int n, int sum, int power)
{
    int p = pow(n, power);
    if (p > sum)
        return;

    if (p == sum)
    {
        totalCount++;
        return;
    }
    calcCount(n + 1, sum - p, power);
    calcCount(n + 1, sum, power);
}

int powerSum(int x, int n)
{
    //basically x is what needs to be acheived with n's power.
    for (int i = 1; i * i <= n; i++)
    {
        calcCount(i, x, n);
    }
    return totalCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin >> x >> n;
    cout << powerSum(x, n) << endl;
    return 0;
}