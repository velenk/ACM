#include <bits/stdc++.h>

using namespace std;

int a[5003], b[5003];

int main(){
    int n0;
    cin >> n0;
    while (n0--) {
        int m, k;
        cin >> m >> k;
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        int need = 0;
        int count = 0;
        while (need <= k) {
            need = 0;
            count++;
            for (int i = 0; i < m; ++i) {
                if (a[i] * count > b[i]) {
                    need += a[i] * count - b[i];
                }
            }
        }
        cout << count-1 << endl;
    }
    return 0;
}
