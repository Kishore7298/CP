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
    int d = k-1;
    while (d<n) {
        for (int i=0; i<n-d; i++) {
            int ans = 0;
            for (int j=0; j<n-d; j++) {
                if (j==0) {
                    //compute the difference manually
                    ans =0;
                    for (int m=i; m <= i+d; m++) {
                        if (s1[m] != s2[m]) {
                            ans++;
                        }
                    }
                    if (ans <= k) {
                        numCount++;
                    }
                }
                else {
                    //applying sliding window
                    if (s1[i] != s2[j-1]) {
                        ans--;
                    }
                    if (s1[i+d-1] != s2[j+d-1]) {
                        ans++;
                    }
                    if (ans <= k) {
                        numCount++;
                    }
                }
            }
        }
        d++;
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