#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " -> " << freq[s[i] - 'a'] << endl;
    }
    return 0;
}