#include <iostream>
#include <string>
using namespace std;

int MinRoughness(string s, int n) {
    int i, j, k, l = s.length();
    int count[30] = { };
    for (i = 0; i < l ;++i) {
        count[s[i] - 'a']++;
    }
    int ret = 10000;
    for (i = 0; i <= 50; ++i) {
        for (j = i; j <= 50; ++j) {
            int m = 0;
            for (k = 0; k < 26; ++k) {
                if (count[k] < i) {
                    m += count[k];
                } else if (count[k] > j) {
                    m += count[k] - j;
                }
            }
            if (m <= n) {
                ret = min(ret, j-i);
            }
        }
    }
    return ret;
}

int main() {
    string s;
    while (cin >> s) {
        int n;
        cin >> n;
        int res = MinRoughness(s, n);
        cout << res << endl;
    }
    return 0;
}
