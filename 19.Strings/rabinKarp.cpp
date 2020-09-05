#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int power(int num, int pow)
{
    int base = 1;
    while (pow != 1)
    {
        if (pow % 2)
        {
            //odd
            base = (base * num) % mod;
            pow--;
        }
        else
        {
            //even
            num = (num * num) % mod;
            pow = pow / 2;
        }
    }
    return (base * num) % mod;
}

int countPatterns(string s, string p)
{
    int count = 0;
    int prime[p.length()];
    /******************* Compute hash for p *************/
    int patternHash = 0;
    int sp = 1;
    for (int i = 0; i < p.length(); i++)
    {
        patternHash = (patternHash + ((p[i] - 'a' + 1) * sp) % mod) % mod;
        prime[i] = sp;
        sp = (sp * 31) % mod;
    }
    /**********************************************************/
    /**************** Compute the hash of string for p elements ******/
    int stringHash = 0;
    int pp = 1;
    for (int i = 0; i < p.length(); i++)
    {
        stringHash = (stringHash + ((s[i] - 'a' + 1) * pp) % mod) % mod;
        pp = (pp * 31) % mod;
    }
    /*****************************************************************/
    if (stringHash == patternHash)
        count++;
    for (int i = 1; i < (s.length() + p.length()); i++)
    {
        stringHash = (stringHash - (s[i - 1] - 'a' + 1) + mod) % mod;
        stringHash = (stringHash * power(31, mod - 2)) % mod;
        stringHash = (stringHash + ((s[i + p.length() - 1] - 'a' + 1) * prime[p.length() - 1]) % mod) % mod;
        if (stringHash == patternHash)
            count++;
    }
    return count;
}

signed main()
{
    string s;
    cin >> s;
    string pattern;
    cin >> pattern;
    cout << countPatterns(s, pattern) << endl;
    return 0;
}