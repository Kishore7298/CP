#include <bits/stdc++.h>

using namespace std;

void printNextSmaller(int a[], int n)
{
    stack<int> st;
    int smaller[n] = {0};
    for (int i = 0; i < n; i++)
    {
        while (st.empty() != true && st.top() >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            smaller[i] = -1;
        }
        else
        {
            smaller[i] = st.top();
        }
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << smaller[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    printNextSmaller(a, n);
    return 0;
}