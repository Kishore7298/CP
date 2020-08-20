#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll numberOfPlays(ll n)
{
    ll count = 0;
    ll rem = 0;
    while (n != 1)
    {
        if (n % 2 != 0)
        {
            if (rem > 0)
            {
                rem--;
                n++;
            }
            else
            {
                rem++;
                n--;
            }
        }
        while (n % 2 == 0)
        {
            n = n / 2;
            count++;
        }
    }
    if (rem > 0)
    {
        count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cout << numberOfPlays(n) << endl;
    return 0;
}