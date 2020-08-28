#include <bits/stdc++.h>
#define ll long long
using namespace std;

int makeStringValid(string s)
{
    int count = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                count++;
    }
    return count + st.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << makeStringValid(s) << endl;
    return 0;
}