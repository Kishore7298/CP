#include <bits/stdc++.h>

using namespace std;

string isSharpenable(int a[], int n)
{
    int leftMax = -1;
    for (int i = 0; i < n; i++)
    {
        //left to right
        if (a[i] >= i)
        {
            continue;
        }
        else
        {
            leftMax = i - 1;
            break;
        }
    }
    if (leftMax == -1)
    {
        //left to right iteration is complete
        return "Yes";
    }
    int rightMax = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        //right to left
        if (a[i] >= n - (i + 1))
        {
            continue;
        }
        else
        {
            rightMax = i + 1;
            break;
        }
    }
    if (rightMax == -1)
        return "Yes";

    if (leftMax >= rightMax)
    {
        return "Yes";
    }
    return "No";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << isSharpenable(a, n) << endl;
    }
    return 0;
}