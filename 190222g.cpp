#include <iostream>
#include <cmath>

using namespace std;

int s[501][501][501];

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m] = { };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i1 = 0; i1 < n-1; ++i1) {
            for (int i2 = i1+1; i2 < n; ++i2) {
                for (int j = 0; j < m; ++j) {
                    s[i1][i2][j] = min(a[i1][j],a[i2][j]);
                }
            }
        }
        int maxi = 0;
        for (int i1 = 0; i1 < n-1; ++i1) {
            for (int i2 = i1+1; i2 < n; ++i2) {
                int maxi1 = 0;
                int maxi2 = 0;
                for (int j = 0; j < m; ++j) {
                    if (maxi1 < s[i1][i2][j]) {
                        if (maxi2 < s[i1][i2][j]) {
                            maxi1 = maxi2;
                            maxi2 = s[i1][i2][j];
                        } else {
                            maxi1 = s[i1][i2][j];
                        }
                    }
                }
                if (maxi < maxi1) {
                    maxi = maxi1;
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
