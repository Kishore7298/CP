#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long int a[n], prefixSum[n];
        for (long int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
            {
                prefixSum[i] = a[i];
            }
            else
            {
                if (a[i] != -1)
                {
                    prefixSum[i] = prefixSum[i - 1] + a[i];
                }
                else
                {
                    //a[i] is -1
                    prefixSum[i] = prefixSum[i - 1] + (prefixSum[i - 1] / i);
                    a[i] = prefixSum[i - 1] / (i);
                }
            }
        }
        for (long int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}