#include <iostream>

using namespace std;

int numberOfIntegers(string s1, string s2, int n, int k)
{
    int numCount = 0;
    if (k - 1 > 0)
    {
        for (int i = 0; i < k - 1; i++)
        {
            numCount += ((n - i) * (n - i));
        }
    }
    return numCount;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s1, s2;
        cin >> s1 >> s2;
        cout << numberOfIntegers(s1, s2, n, k) << endl;
    }
}