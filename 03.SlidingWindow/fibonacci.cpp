#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;

int f[MAX] = {0};

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k);

    return f[n];
}

// Computes value of first Fibonacci numbers
int calculateSum(int n)
{
    return fib(n + 2) - 1;
}

// Driver program to test above function
int main()
{
    int n = 4;
    cout << "Sum of Fibonacci numbers is : "
         << calculateSum(n) << endl;
    return 0;
}
