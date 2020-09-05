#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        if (n == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            int count = 0;
            string result;
            for (int i = 0; i < n; i++)
            {
                if ((s[i] - '0') % 2)
                {
                    result += s[i];
                    count++;
                }
                if (count == 2)
                    break;
            }
            if (count == 2)
                cout << result << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}