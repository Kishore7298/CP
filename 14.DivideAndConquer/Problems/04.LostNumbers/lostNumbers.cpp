#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    vector<int> p = {4, 8, 15, 16, 23, 42};
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cout.flush();
        cin >> a[i];
    }
    do
    {
        bool flag = true;
        for (int i = 0; i < 4; i++)
        {
            if (p[i] * p[i + 1] != a[i])
                flag = false;
        }
        if (flag == true)
            break;
    } while (next_permutation(p.begin(), p.end()));
    cout << "!";
    for (auto i : p)
    {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();
    return 0;
}