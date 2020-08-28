#include <bits/stdc++.h>

using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (precedence(st.top()) >= precedence(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (st.top() != 'N')
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << infixToPostfix(s) << endl;
    return 0;
}

bool isLucky(int n, int &counter)
{
    if (n >= counter)
    {
        return false;
    }
    if (n % counter == 1)
    {
        return true;
    }
    return isLucky(n - ((n + 1) / counter), counter);
}