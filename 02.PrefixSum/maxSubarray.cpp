#include <iostream>

using namespace std;

/*
    Problem statement: Given an Array, find the maxium sum of the subarray of given length.
    Input: 
    k = 3 (substring length)
    n = 5 (array length)
    a[n] = [1,2,4,2,9]

    Output: 
    15 (maxsum)
*/

/* This is further optimized in Sliding window section */

int main()
{

    int n, k;

    cin >> n >> k;
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
    int maxSum = INT32_MIN;
    int l, r;
    for (int i = 0; i <= n - k; i++)
    {
        l = i;
        r = i + k - 1;
        if (i == 0)
        {
            if (prefixSum[r] > maxSum)
            {
                maxSum = prefixSum[r];
            }
        }
        else
        {
            int sum = prefixSum[r] - prefixSum[l - 1];
            if (maxSum < sum)
            {
                maxSum = sum;
            }
        }
    }
    cout << maxSum << endl;
}