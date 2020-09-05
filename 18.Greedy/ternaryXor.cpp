#include <bits/stdc++.h>

using namespace std;

void maximinString(string s, int n)
{
    string a, b;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            a += '0';
            b += '0';
        }
        else if (s[i] == '1')
        {
            if (!flag)
            {
                a += '1';
                b += '0';
                flag = true;
            }
            else
            {
                a += '0';
                b += '1';
            }
        }
        else if (s[i] == '2')
        {
            if (flag)
            {
                a += '0';
                b += '2';
            }
            else
            {
                a += '1';
                b += '1';
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        maximinString(s, n);
    }
    return 0;
}