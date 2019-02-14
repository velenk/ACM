#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, cnt;
    cnt = 0;
    cin >> a >> b;
    int s[a][b] = { };
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int flag = 0;
            s[i][j] = 1;
            cnt++;
            for (int i0 = 0; i0 < a; ++i0) {
                for (int j0 = 0; j0 < b; ++j0) {
                    if (flag) break;
                    if (s[i0][j0] == 0 || (i0 == i && j0 == j)) continue;
                    if (i0-j0 == i-j || i0+j0 == i+j) {
                        flag = 1;
                    }
                }
            }
            if (flag) {
                s[i][j] = 0;
                cnt--;
            } else {
                cout << i << j << endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
