#include <bits/stdc++.h>
#define ll long long

using namespace std;

void printString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    if (st.empty())
    {
        cout << "KHALI" << endl;
    }
    else
    {
        string ans = "";
        while (st.empty() != true)
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        printString(s);
    }
    return 0;
}