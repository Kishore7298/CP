//next greater element in circular array
#include <bits/stdc++.h>

using namespace std;

void printNextGreater(int a[], int n)
{
    stack<int> st;
    int temp[n];
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (st.empty() != true && st.top() <= a[i % n])
            st.pop();
        if (st.empty() == true)
        {
            if (i < n)
                temp[i] = -1;
            st.push(a[i % n]);
        }
        else
        {
            if (st.top() > a[i % n])
            {
                if (i < n)
                    temp[i] = st.top();
                st.push(a[i % n]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    printNextGreater(a, n);
    return 0;
}