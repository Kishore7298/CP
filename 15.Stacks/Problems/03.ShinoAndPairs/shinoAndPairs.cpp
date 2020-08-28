#include <bits/stdc++.h>
#define ll long long

using namespace std;

int pairs(int a[], int n)
{
    stack<int> st;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(a[i]);
        else
        {
            while (st.empty() != true && st.top() < a[i])
            {
                st.pop();
                count++;
            }
            if (st.empty() != true)
            {
                if (st.top() >= a[i])
                    count++;
            }
            st.push(a[i]);
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << pairs(a, n) << endl;
    return 0;
}