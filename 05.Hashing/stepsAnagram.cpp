#include <iostream>

using namespace std;

/*
    Problem Statement: Number of steps required to make two strings anagram
    I/p:
    a: dear (1st string)
    b: care (2nd string)

    O/p: 2 (2 charecters - d, c)
*/
int makeAnagram(string a, string b)
{
    int arr[255] = {0};
    int brr[255] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        arr[a[i] - NULL]++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        brr[b[i] - NULL]++;
    }
    int sum = 0;
    for (int i = 0; i < 255; i++)
    {
        sum += abs(arr[i] - brr[i]);
    }
    return sum;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int steps = makeAnagram(a, b);
    cout << steps;
    return 0;
}