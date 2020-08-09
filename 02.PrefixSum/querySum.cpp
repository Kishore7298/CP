#include <iostream>

using namespace std;

/*
    Problem statement: Return the sum of the subarray in the given query
    Input:
    n = 5 (array length)
    a[n] = [1, 2, 3, 4, 5]
    q = 2 (Number of queryies)
    l = 0 r = 4 (1st query, left and right range values)
    l = 1 r = 4 (2nd query)

    Output:
    15 (First query sum)
    14 (Second query sum)

*/

int main()
{
    int n;
    cin >> n;
    int a[n], prefixSum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            prefixSum[i] = a[i];
        }
        else
        {
            prefixSum[i] = prefixSum[i - 1] + a[i];
        }
    }
    int q;
    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        if (l == 0)
        {
            cout << prefixSum[r] << endl;
        }
        else
        {
            cout << prefixSum[r] - prefixSum[l - 1] << endl;
        }
    }

    return 0;
}