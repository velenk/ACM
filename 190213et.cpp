#include <iostream>
using namespace std;
#define mode 1000000007

int main()
{
    int n;
    cin >> n;
    int now[2][1] = {{1}, {0}}, matrix[2][2] = {{1, 1}, {1, 0}};
    while (n) {
        int a, b, c, d;
        if (n & 1) {
            a = matrix[0][0] * now[0][0] + matrix[0][1] * now[1][0];
            b = matrix[1][0] * now[0][0] + matrix[1][1] * now[1][0];
            now[0][0] = a % mode, now[1][0] = b % mode;
        }
        a = matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0];
        b = matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1];
        c = matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0];
        d = matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1];
        matrix[0][0] = a % mode, matrix[0][1] = b % mode, matrix[1][0] = c % mode, matrix[1][1] = d % mode;
        n /= 2;
    }
    cout << now[1][0];
}
