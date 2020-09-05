#include <bits/stdc++.h>

using namespace std;

void constructPrefix(string s)
{
    int len = 0;
    int i = 1;
    int prefix[s.length()] = {0};
    while (i < s.length())
    {
        if (s[i] == s[len])
        {
            prefix[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = prefix[len - 1];
            }
            else
            {
                i++;
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    constructPrefix(s);
    return 0;
}