#include <bits/stdc++.h>

using namespace std;
//this algorithm uses meet in the middle pattern

map<int, int> maxSumDivisibleByK(vector<int> a, int n, int k)
{
    map<int, int> mapping;
    for (int counter = 0; counter < 1 << n; counter++)
    {
        int tempSum = 0;
        for (int j = 0; j < n; j++)
        {
            if (counter & 1 << j)
            {
                tempSum += a[j];
            }
        }
        int rem = tempSum % k;
        if (mapping.find(rem) != mapping.end())
        {
            // mapping already exists
            if (mapping[rem] < tempSum)
            {
                mapping[rem] = tempSum;
            }
        }
        else
        {
            mapping.insert(make_pair(rem, tempSum));
        }
    }
    return mapping;
}

int generateSplits(int a[], int n, int k)
{
    int mid = n / 2;
    vector<int> leftSplit;
    vector<int> rightSplit;
    for (int i = 0; i <= mid; i++)
        leftSplit.push_back(a[i]);
    for (int i = mid + 1; i < n; i++)
        rightSplit.push_back(a[i]);
    auto leftMapping = maxSumDivisibleByK(leftSplit, n, k);
    auto rightMapping = maxSumDivisibleByK(rightSplit, n, k);
    int maxi = 0;
    for (auto i : leftMapping)
    {
        int leftRem = i.first;
        int lookup = (k - leftRem) % k;
        maxi = max(i.second + rightMapping[lookup], maxi);
    }
    return maxi;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << generateSplits(a, n, k) << endl;
    return 0;
}