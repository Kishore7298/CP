#include <bits/stdc++.h>
#define ll long long

using namespace std;

void merge(vector<long long> &a, long long l, long long m, long long h, long long &counter)
{
    vector<int> sorted;
    long long start = l;
    long long mid = m + 1;
    while (start <= m && mid <= h)
    {
        if (a[start] < a[mid])
        {
            sorted.push_back(a[start++]);
        }
        else
        {

            auto itr = upper_bound(a.begin() + l, a.begin() + m + 1, (ll)(2 * a[mid]));
            if (itr != a.begin() + m + 1)
            {
                long long index = itr - a.begin();
                counter += m - index + 1;
            }
            sorted.push_back(a[mid++]);
        }
    }
    while (start <= m)
        sorted.push_back(a[start++]);
    while (mid <= h)
        sorted.push_back(a[mid++]);
    for (long long i = l; i <= h; i++)
    {
        a[i] = sorted[i - l];
    }
}

void mergeSort(vector<long long> &a, long long low, long long high, long long *counter)
{
    if (high <= low)
    {
        return;
    }
    long long mid = low + (high - low) / 2;
    mergeSort(a, low, mid, counter);
    mergeSort(a, mid + 1, high, counter);
    merge(a, low, mid, high, *counter);
}

int reversePairs(vector<int> &nums)
{
    long long counter = 0;
    vector<long long> random;
    for (auto i : nums)
    {
        random.push_back(i);
    }
    mergeSort(random, 0, nums.size() - 1, &counter);
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> nums;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int elem;
            cin >> elem;
            nums.push_back(elem);
        }
        cout << reversePairs(nums) << endl;
    }
    return 0;
}