#include <bits/stdc++.h>
#define int long long

#define mod 1000000007

using namespace std;

/*
Problem Statement: Check if the substring in the given query are equal or not!
*/

int modPower(int num, int power)
{
    int base = 1;
    while (power != 1)
    {
        if (power % 2 == 0)
        {
            num = (num * num) % mod;
            power = power / 2;
        }
        else
        {
            base = (base * num) % mod;
            power--;
        }
    }
    return (base * num) % mod;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        //Compute the hash--------------
        int hashValue = 0;
        int p = 1;
        int prefixHash[s.length()];
        int prefixPrime[s.length()];
        for (int i = 0; i < s.length(); i++)
        {
            hashValue = (hashValue + ((s[i] - 'a' + 1) * p) % mod) % mod;
            prefixHash[i] = hashValue;
            prefixPrime[i] = p;
            p = (p * 31) % mod;
        }
        //--------------------------------
        int q;
        cin >> q;
        while (q--)
        {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            /*
                (prefix[j1]-prefix[i1-1])/p^i1
            */
            int sol1 = (prefixHash[j1] - (i1 > 0 ? prefixHash[i1 - 1] : 0) + mod) % mod;
            sol1 = (sol1 * modPower(prefixPrime[i1], mod - 2)) % mod; //fermat's little theorem
            int sol2 = (prefixHash[j2] - (i2 > 0 ? prefixHash[i2 - 1] : 0) + mod) % mod;
            sol2 = (sol2 * modPower(prefixPrime[i2], mod - 2)) % mod; //fermat's little theorem
            if (sol1 == sol2)
                cout << "Substring are equal!" << endl;
            else
                cout << "Substring are not equal!" << endl;
        }
    }
    return 0;
}