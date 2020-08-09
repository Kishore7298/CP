#include <bits/stdc++.h>

using namespace std;
// time complexity: O(v¯¯n)
bool isPrime(int n)
{
    if (n <= 2)
    {
        return true;
    }
    bool flag = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(n) << endl;
    return 0;
}