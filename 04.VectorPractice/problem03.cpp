#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> s;
    int q;
    cin >> q;
    int operation, element;
    for (int i = 0; i < q; i++)
    {
        cin >> operation >> element;
        if (operation == 1)
        {
            s.insert(element);
        }
        else if (operation == 2)
        {
            s.erase(element);
        }
        else if (operation == 3)
        {
            auto itr = s.find(element);
            if (itr != s.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}