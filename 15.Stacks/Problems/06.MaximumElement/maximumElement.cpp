#include <bits/stdc++.h>
#define ll long long

//Link to the question: https://www.hackerrank.com/challenges/maximum-element/problem

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    vector<int> st;
    cin >> t;
    while (t--)
    {
        int q, n;
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> n;
            st.push_back(n);
            break;
        case 2:
            //delete
            st.pop_back();
            break;
        case 3:
            int maxi = st.back();
            for (auto i : st)
            {
                if (i > maxi)
                    maxi = i;
            }
            cout << maxi << endl;
            break;
        }
    }
    return 0;
}