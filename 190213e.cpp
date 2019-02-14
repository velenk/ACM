#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long LL;

#define mode 1000000007

void calc(LL ans[70][70], LL matrix[70][70], LL n)
{
    LL tmp[70][70];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                tmp[i][j] +=  matrix[i][k] * ans[k][j] % mode;
                tmp[i][j] %= mode;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans[i][j] = tmp[i][j];
        }
    }
    return;
}

int main()
{
    int n0;
    cin >> n0;
    while (n0--) {
    LL n, k, k0, matrix[70][70] = { }, ans[70][70] = { };
    cin >> n >> k;
    k0 = k+2;
    for (int i = 1; i <= k0; ++i) {
        for (int j = 0; j <= k0; ++j) {
            if (i == 1) {
                if (j == 1) {
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = 0;
                }
            } else if (i == k0) {
                matrix[i][j] = matrix[i-1][j];
                if (j == k0) {
                    matrix[i][j] = 2;
                }
            } else if (j > i) {
                matrix[i][j] = 0;
            } else if (j == 1) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = matrix[i-1][j-1] + matrix [i-1][j];
            }
        }
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= k0; ++i) {
        for (int j = 1; j <= k0; ++j) {
            if (j == 1 && i == 1) {
                ans[i][j] = 1;
            } else {
                ans[i][j] = 0;
            }
        }
    }
    while (n) {
        if (n & 1) {
            calc(ans, matrix, k0);
        }
        calc(matrix, matrix, k0);
        n /= 2;
    }
    cout << ans[k0][1]%mode << endl;
    }
    return 0;
}

