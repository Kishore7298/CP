#include <iostream>

using namespace std;
/*

Pattern:
    *   
  * * *
* * * * *

*/

int main()
{
    int lines;
    cin >> lines;
    int gridLength = lines + lines - 1;
    for (int i = 0; i < lines; i++)
    {
        int leftRange = ((gridLength - 1) / 2) - i;
        int rightRange = ((gridLength - 1) / 2) + i;
        for (int j = 0; j < gridLength; j++)
        {
            if (j >= leftRange && j <= rightRange)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}