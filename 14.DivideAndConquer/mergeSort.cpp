#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int l, int m, int h)
{
    vector<int> sorted;
    int start = l;
    int mid = m + 1;
    while (start <= m && mid <= h)
    {
        if (a[start] < a[mid])
            sorted.push_back(a[start++]);
        else
            sorted.push_back(a[mid++]);
    }
    while (start <= m)
        sorted.push_back(a[start++]);
    while (mid <= h)
        sorted.push_back(a[mid++]);
    for (int i = l; i <= h; i++)
    {
        a[i] = sorted[i - l];
    }
}

void mergeSort(int a[], int low, int high)
{
    if (high <= low)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}