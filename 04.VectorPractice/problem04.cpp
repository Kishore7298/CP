#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    int operation, score;
    map<string, int> m;
    string name;
    for (int i = 0; i < q; i++)
    {
        cin >> operation >> name;
        if (operation == 1)
        {
            cin >> score;
            if (m.find(name) != m.end())
            {
                m[name] += score;
            }
            else
            {
                m.insert(make_pair(name, score));
            }
        }
        else if (operation == 2)
        {
            m.erase(name);
        }
        else if (operation == 3)
        {
            cout << m[name] << endl;
        }
        else
        {
            cout << " Unsupported operation" << endl;
        }
    }
    return 0;
}