/*
Problem Statement: Find the maximum sum in the subsequence.
This problem is a good example of the meet in the middle pattern
*/
#include <bits/stdc++.h>

using namespace std;

int maxSumSubsequence(vector<int> a, int n)
{
    if (n <= 0)
        return 0;
    int max = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        int tempSum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                tempSum += a[j];
        }
        if (tempSum > max)
            max = tempSum;
    }
    return max;
}

int genereateSplits(int a[], int n)
{
    vector<int> leftSplit, rightSplit;
    for (int i = 0; i < n / 2; i++)
        leftSplit.push_back(a[i]);
    for (int i = n / 2; i < n; i++)
        rightSplit.push_back(a[i]);
    int leftMax = maxSumSubsequence(leftSplit, leftSplit.size());
    int rightMax = maxSumSubsequence(rightSplit, rightSplit.size());
    return leftMax + rightMax;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << genereateSplits(a, n) << endl;
    return 0;
}