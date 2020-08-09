#include <iostream>

using namespace std;

void findRangeSum(int *prefixSum, int *a, int n, int i1, int j1, int i2, int j2)
{
    int sum = *((prefixSum + i2 * n) + j2);
    if (i1 > 0)
    {
        sum -= *((prefixSum + (i1 - 1) * n) + j2);
    }
    if (j1 > 0)
    {
        sum -= *((prefixSum + i2 * n) + (j1 - 1));
    }
    if ((i1 > 0) && (j1 > 0))
    {
        sum += *((prefixSum + (i1 - 1) * n) + (j1 - 1));
    }
    cout << sum << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int prefixSum[n][n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prefixSum[0][0] = a[0][0];
        }
        else
        {
            prefixSum[i][0] = prefixSum[i - 1][0] + a[i][0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        prefixSum[0][i] = prefixSum[0][i - 1] + a[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] + a[i][j] - prefixSum[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    int i1, i2, j1, j2;
    while (q--)
    {
        cin >> i1 >> j1 >> i2 >> j2;
        findRangeSum((int *)prefixSum, (int *)a, n, i1, j1, i2, j2);
    }
    return 0;
}