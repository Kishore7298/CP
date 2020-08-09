#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if ((n / i) != i)
                st.push(n / i);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}