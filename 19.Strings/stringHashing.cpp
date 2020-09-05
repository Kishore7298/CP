#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int hashString(string s)
{
    int hashValue = 0;
    int p = 1;
    for (int i = 0; i < s.length(); i++)
    {
        hashValue = (hashValue + ((s[i] - 'a' + 1) * p) % mod) % mod;
        p = (p * 31) % mod;
    }
    return hashValue;
}

int main()
{
    string s;
    cin >> s;
    cout << hashString(s) << endl;
    return 0;
}