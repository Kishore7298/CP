#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int x)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return mid + 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            cout << "Something went wrong!!" << endl;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    cout << binarySearch(a, n, x) << endl;
    return 0;
}