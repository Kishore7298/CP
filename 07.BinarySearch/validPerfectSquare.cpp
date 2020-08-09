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