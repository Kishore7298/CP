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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    int maxSum = sum;
    int l = 0, r = 0;
    for (int i = 0; i < n - k; i++)
    {
        l = i;
        r = i + k - 1;
        sum -= a[l++];
        sum += a[++r];
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << endl;
}