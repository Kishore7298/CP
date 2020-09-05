#include <bits/stdc++.h>
#define mod 100000

using namespace std;

int visited[mod + 1];

int numberOfSteps(int a[], int n, int start, int end)
{
    queue<pair<int, int>> qu;
    for (int i = 0; i < n; i++)
    {
        int elem = (a[i] * start) % mod;
        visited[elem] = 1;
        qu.push({elem, 1});
    }
    while (qu.empty() != true)
    {
        pair<int, int> elem = qu.front();
        if (elem.first == end)
            return elem.second;
        for (int i = 0; i < n; i++)
        {
            int prod = (elem.first * a[i]) % mod;
            if (visited[prod] != true)
            {
                qu.push({prod, elem.second + 1});
            }
        }
        qu.pop();
    }
    return -1;
}

int main()
{
    int start, end, n;
    cin >> start >> end >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << numberOfSteps(a, n, start, end) << endl;
    return 0;
}