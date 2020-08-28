#include <bits/stdc++.h>

using namespace std;

bool validateParenthesis(string s)
{
    stack<int> st;
    bool isValid = true;
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            st.push(s[i]);
            break;
        case ')':
            if (st.empty() == true || st.top() != '(')
            {
                isValid = false;
                break;
                break;
            }
            st.pop();
            break;
        case '}':
            if (st.empty() == true || st.top() != '{')
            {
                isValid = false;
                break;
                break;
            }
            st.pop();
            break;
        case ']':
            if (st.empty() == true || st.top() != '[')
            {
                isValid = false;
                break;
                break;
            }
            st.pop();
            break;
        }
    }
    if (st.empty() != true)
        isValid = false;
    return isValid;
}

int main()
{
    string s;
    cin >> s;
    cout << validateParenthesis(s) << endl;
    return 0;
}
