#include <iostream>
#include <algorithm>

using namespace std;

int getLargestDistance(long int a[], long int s, long int c)
{
    long int low, high, mid;
    low = 1;
    sort(a, a + s);
    high = a[s - 1];
    int currentSol = 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        long int cowsLeft = c;
        int i = 1;
        long int solution = a[0];
        while (cowsLeft && i < s)
        {
            i++;
            if (a[i] >= solution + mid)
            {
                cowsLeft--;
                solution = a[i];
            }
        }
        if (cowsLeft == 0)
        {
            currentSol = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return currentSol;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int s, c;
        cin >> s >> c;
        long int a[s];
        for (int i = 0; i < s; i++)
        {
            cin >> a[i];
        }
        cout << getLargestDistance(a, s, c) << endl;
    }
    return 0;
}