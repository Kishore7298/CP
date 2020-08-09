#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL t;
    cin >> t;
    while (t--)
    {
        string s;
        LL ones = 0, zeros = 0, ans = 0, range, n, i, j;
        cin >> s;
        n = s.length();
        for (i = 1; i * i + i <= n; i++)
        {
            zeros = 0;
            ones = 0, range = i * i + i;
            for (j = 0; j < range; j++)
            {
                if (s[j] == '0')
                    zeros++;
                else
                    ones++;
            }
            if (ones == i) // edit
                ans++;
            for (j = range; j < n; j++)
            {
                if (s[j - range] == '0')
                    zeros--;
                else
                    ones--;
                if (s[j] == '0')
                    zeros++;
                else
                    ones++;
                if (ones == i) // edit
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}