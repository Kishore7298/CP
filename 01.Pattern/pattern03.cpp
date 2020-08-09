#include <bits/stdc++.h>

using namespace std;

/**
 Input : n = 5 (odd number)
 Pattern:
    1
    1 2
    1 2 3
    1 2
    1

 Input : n = 7 
 Pattern:
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3
    1 2
    1
 */

int main()
{

    int n;
    cin >> n;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
        if (i >= n / 2)
        {
            k--;
        }
        else
        {
            k++;
        }
    }
    return 0;
}
