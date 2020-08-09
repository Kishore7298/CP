#include <iostream>
using namespace std;

bool isPerfectSquare(int num)
{
    if (num <= 1)
    {
        return true;
    }

    long int low, high, mid;
    low = 1;
    high = num - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid * mid == num)
        {
            return true;
        }
        else if (mid * mid < num)
        {
            low = mid + 1;
        }
        else if (mid * mid > num)
        {
            high = mid - 1;
        }
        else
        {
            cout << "Something went wrong!!" << endl;
            return false;
        }
    }
    return false;
}

int main()
{
    int num;
    cin >> num;
    cout << isPerfectSquare(num) << endl;
    return 0;
}

int binarySearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarySearch(a, l, mid - 1, x);
        return binarySearch(a, mid + 1, r, x);
    }
    return -1;
}