#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, m, w;
    map<string, int> M;
    while (cin >> n) {
        int turn = 0;
        cin >> m >> w;
        int a[n] = { };//initial
        int s[n] = { };//now
        int b[m] = { };//country
        int c[m] = { };//time
        string k[n] = { };
        M.clear();
        int flag0 = 0;
        for (int i =0; i < n; ++i) {
            string s;
            int temp;
            cin >> s;
            cin >> temp;
            M[s] = i;
            k[i] = s;
            a[i] = temp;
            if (temp > 0) {
                flag0 = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            string s;
            int temp;
            cin >> temp;
            cin >> s;
            b[i] = M[s];
            c[i] = temp;
        }
        int flag = 1;
        int win = 0;
        int m0 = 0;
        int mini = 1e8;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int temp = w/(a[i]+1);
            if (temp < mini && temp > 0) {
                mini = temp;
            }
        }
        while (flag0 && flag) {
            turn++;
            while (mini > 2000) {
                for (int i = 0; i < n; ++i) {
                    s[i] += a[i] * 1000;
                }
                turn += 1000;
                if (cnt > 1000) {
                    flag0 = 0;
                    break;
                }
            }
            while (m0 < m && c[m0] <= turn -2) {
                s[b[m0]] += 20;
                m0++;
            }
            for (int i = 0; i < n; ++i) {
                s[i] += a[i];
                if (s[i] >= w) {
                    win = i;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag0 == 0) {
            cout << "Never\n";
        } else {
            cout << turn << " " << k[win] << endl;
        }
    }
    return 0;
}
