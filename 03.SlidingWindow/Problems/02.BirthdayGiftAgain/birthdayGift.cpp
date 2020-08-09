#include <bits/stdc++.h>

using namespace std;

int countBeauty(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int zeroCount = 0;
        int oneCount = 0;
        for (int j = i; j < s.length(); j++)
        {
            if (s[j] == '0')
            {
                zeroCount += 1;
            }
            else
            {
                oneCount += 1;
            }
            if (zeroCount == (oneCount * oneCount))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countBeauty(s) << endl;
    }
    return 0;
}