#include <iostream>

using namespace std;
/*
    This extended eucledian is used to find the modular multiplicative inverse
    which means,
    (A*A^)%B = 1, Here A^ is the modular multiplicative inverse of A over mod B
*/

/*
  Ax + By = GCD(A, B);
  X = y1
  Y = x1 - |A/B|.y1
*/
int d, x, y;
void extendedEucledian(int A, int B)
{
    if (B == 0)
    {
        d = A;
        y = 0;
        x = 1;
    }
    else
    {
        extendedEucledian(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int main()
{
    int A, B;
    cin >> A >> B;
    extendedEucledian(A, B);
    cout << "GCD(A, B): " << d << endl;
    cout << "x :" << x << " y: " << y << endl;
}