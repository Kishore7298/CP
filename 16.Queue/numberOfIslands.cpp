#include <bits/stdc++.h>

using namespace std;
int visited[10000][10000];

bool isValidIndex(int i, int j, int n, int m)
{
    if (i >= 0 && j >= 0 && i < n && j < m)
        return true;
    return false;
}
const int maxL = 10000;
void bfs(int a[][maxL], int i, int j, int n, int m)
{
    visited[i][j] = 1;
    queue<pair<int, int>> qu;
    qu.push({i, j});
    while (qu.empty() != true)
    {
        pair<int, int> elem = qu.front();
        int ii = elem.first;
        int jj = elem.second;
        if (isValidIndex(ii + 1, jj, n, m) && a[ii + 1][jj] == 1 && visited[ii + 1][jj] != true)
        {
            //bottom
            visited[ii + 1][jj] = true;
            qu.push({ii + 1, jj});
        }
        if (isValidIndex(ii, jj + 1, n, m) && a[ii][jj + 1] == 1 && visited[ii][jj + 1] != true)
        {
            //right
            visited[ii][jj + 1] = true;
            qu.push({ii, jj + 1});
        }
        if (isValidIndex(ii, jj - 1, n, m) && a[ii][jj - 1] == 1 && visited[ii][jj - 1] != true)
        {
            //left
            visited[ii][jj - 1] = true;
            qu.push({ii, jj - 1});
        }
        if (isValidIndex(ii - 1, jj, n, m) && a[ii - 1][jj] == 1 && visited[ii - 1][jj] != true)
        {
            //top
            visited[ii - 1][jj] = true;
            qu.push({ii - 1, jj});
        }
        qu.pop();
    }
    return;
}

int main()
{
    int m, n;
    cin >> n >> m;
    int a[n][maxL];
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && visited[i][j] != 1)
            {
                count++;
                bfs(a, i, j, n, m);
            }
        }
    cout << count << endl;
    return 0;
}