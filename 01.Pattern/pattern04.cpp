#include <iostream>

using namespace std;

/*
    Problem statement: Print all the possible subarray for the given array.

    Input:
    n = 5
    a[n] = [1, 2, 3, 4, 5]

    Output:
    1
    1 2 
    1 2 3
    1 2 3 4
    1 2 3 4 5
    2
    2 3
    2 3 4
    2 3 4 5
    3
    3 4
    3 4 5
    4
    4 5
    5

*/

int main()
{

    int n;

    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}