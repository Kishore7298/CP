#include <bits/stdc++.h>

using namespace std;

int sumOfFactors(int number)
{
    int sum = 1;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
            if (i * i != number)
            {
                sum += number / i;
            }
        }
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int number;
        cin >> number;
        cout << sumOfFactors(number) << endl;
    }
    return 0;
}