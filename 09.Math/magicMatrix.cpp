#include <bits/stdc++.h>
/*
Problem statement:
    Find the nth term of the fibonacci sequence.

This Problem demonstrates the use of magic matrix
*/
using namespace std;

vector<vector<int>> matrixMultiply(vector<vector<int>> a, vector<vector<int>> b)
{
    int r1 = a.size();
    int c1 = a[0].size();
    int r2 = b.size();
    int c2 = b[0].size();

    vector<vector<int>> result;

    for (int i = 0; i < r1; ++i)
    {
        result.push_back({});
        for (int j = 0; j < c2; ++j)
        {
            result[i].push_back({0});
            for (int k = 0; k < c1; ++k)
                result[i][j] += a[i][k] * b[k][j];
        }
    }

    return result;
}

vector<vector<int>> matrixExponentiation(vector<vector<int>> matrix, int power)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> identity = {{1, 0}, {0, 1}};

    while (power != 1)
    {
        if (power % 2 == 0)
        {
            matrix = matrixMultiply(matrix, matrix);
            power = power / 2;
        }
        else
        {
            identity = matrixMultiply(identity, matrix);
            power--;
        }
    }
    return matrixMultiply(identity, matrix);
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    vector<vector<int>> rep = {{1, 1}, {1, 0}};
    vector<vector<int>> resultant = matrixMultiply(matrixExponentiation(rep, n - 1), {{1}, {0}});
    return resultant[0][0];
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n - 1) << endl;
    return 0;
}