#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int goodSubstring(string s, string badRef, int atMax)
{
    set<pair<int, int>> st;
    for (int i = 0; i < s.length(); i++)
    {
        int count = 0;
        int hashValue = 0;
        int p = 1;
        int hashValue2 = 0;
        int p2 = 1;
        for (int j = i; j < s.length(); j++)
        {
            if (badRef[(s[j] - 'a')] == '0')
                count++;
            if (count > atMax)
                break;
            hashValue = (hashValue + ((s[j] - 'a' + 1) * p) % mod) % mod;
            hashValue2 = (hashValue2 + ((s[j] - 'a' + 1) * p2) % mod) % mod;
            p = (p * 31) % mod;
            p2 = (p2 * 53) % mod;
            st.insert({hashValue, hashValue2});
        }
    }
    return st.size();
}

signed main()
{
    string s;
    cin >> s;
    string badRef;
    cin >> badRef;
    int atMax;
    cin >> atMax;
    cout << goodSubstring(s, badRef, atMax) << endl;
    return 0;
}